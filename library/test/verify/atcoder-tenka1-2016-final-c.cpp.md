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


# :warning: test/verify/atcoder-tenka1-2016-final-c.cpp
* category: test/verify


[Back to top page](../../../index.html)



## Code
```cpp
int main() {
  Trie< 26, 'a' > trie;
  string S, P[5000];
  int M, W[5000];

  cin >> S;
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> P[i];
    trie.add(P[i]);
  }
  for(int i = 0; i < M; i++) {
    cin >> W[i];
  }
  vector< int > dp(S.size() + 1);
  for(int i = 0; i < S.size(); i++) {
    auto update = [&](int idx) {
      dp[i + P[idx].size()] = max(dp[i + P[idx].size()], dp[i] + W[idx]);
    };
    trie.query(S, update, i, 0);
    dp[i + 1] = max(dp[i + 1], dp[i]);
  }
  cout << dp.back() << endl;
}

```

[Back to top page](../../../index.html)
