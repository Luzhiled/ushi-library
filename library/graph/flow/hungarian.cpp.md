---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/flow/hungarian.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2af6c4bb6ad7cfa010303133dc15971f">graph/flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/flow/hungarian.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 23:02:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/verify/aoj-1163.test.cpp.html">test/verify/aoj-1163.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< typename T >
T hungarian(Matrix< T > &A) {
  const T infty = numeric_limits< T >::max();
  const int N = (int) A.size();
  const int M = (int) A[0].size();
  vector< int > P(M), way(M);
  vector< T > U(N, 0), V(M, 0), minV;
  vector< bool > used;

  for(int i = 1; i < N; i++) {
    P[0] = i;
    minV.assign(M, infty);
    used.assign(M, false);
    int j0 = 0;
    while(P[j0] != 0) {
      int i0 = P[j0], j1 = 0;
      used[j0] = true;
      T delta = infty;
      for(int j = 1; j < M; j++) {
        if(used[j]) continue;
        T curr = A[i0][j] - U[i0] - V[j];
        if(curr < minV[j]) minV[j] = curr, way[j] = j0;
        if(minV[j] < delta) delta = minV[j], j1 = j;
      }
      for(int j = 0; j < M; j++) {
        if(used[j]) U[P[j]] += delta, V[j] -= delta;
        else minV[j] -= delta;
      }
      j0 = j1;
    }
    do {
      P[j0] = P[way[j0]];
      j0 = way[j0];
    } while(j0 != 0);
  }
  return -V[0];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/flow/hungarian.cpp"
template< typename T >
T hungarian(Matrix< T > &A) {
  const T infty = numeric_limits< T >::max();
  const int N = (int) A.size();
  const int M = (int) A[0].size();
  vector< int > P(M), way(M);
  vector< T > U(N, 0), V(M, 0), minV;
  vector< bool > used;

  for(int i = 1; i < N; i++) {
    P[0] = i;
    minV.assign(M, infty);
    used.assign(M, false);
    int j0 = 0;
    while(P[j0] != 0) {
      int i0 = P[j0], j1 = 0;
      used[j0] = true;
      T delta = infty;
      for(int j = 1; j < M; j++) {
        if(used[j]) continue;
        T curr = A[i0][j] - U[i0] - V[j];
        if(curr < minV[j]) minV[j] = curr, way[j] = j0;
        if(minV[j] < delta) delta = minV[j], j1 = j;
      }
      for(int j = 0; j < M; j++) {
        if(used[j]) U[P[j]] += delta, V[j] -= delta;
        else minV[j] -= delta;
      }
      j0 = j1;
    }
    do {
      P[j0] = P[way[j0]];
      j0 = way[j0];
    } while(j0 != 0);
  }
  return -V[0];
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
