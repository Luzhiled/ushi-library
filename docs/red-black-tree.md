## 概要

Red-Black-Tree は平衡二分探索木の一種. RBSTとは異なり葉にデータをもたせる実装(葉木)なので, pool の大きさを $2$ 倍とる必要がある.

merge-split ベースによる実装.

* `RedBlackTree(n, f, M1)`: サイズ `n` で初期化する. ここで `f` は2つの区間の要素をマージする二項演算, `M1` はモノイドの単位元である.
* `split(t, k)`: 木 `t` を $[0, k)[k, n)$ で分割する.
* `split3(t, a, b)`: 木 `t` を $[0, a)[a, b)[b, n)$ で分割する.
* `merge(l, r)`: 木 `l` と木 `r` を併合する.
* `build(v)`: 配列 `v` をもとに木を構築する.
* `dump(r)`: 木 `r` の葉を通りがけ順に格納したものを返す.
* `to_string(r)`: `dump(r)` をスペース区切りで文字列として連結したものを返す.
* `insert(t, k, v)`: 木 `t` の位置 `k` (0-indexed) にノード `v` を挿入する.
* `erase(t, k)`: 木 `t` の位置 `k` (0-indexed) のノードを削除する.
* `query(t, l, r)`: 区間 $[l, r)$ の要素を二項演算した結果を返す.
* `set_element(t, k, x)`: 木 `t` の位置 `k` (0-indexed) のノードを `x` に変更する.
* `push_front(t, v)`: 木 `t` の先頭にノード `v` を挿入する.
* `push_back(t, v)`: 木 `t` の末尾にノード `v` を挿入する.
* `pop_front(t)`: 木 `t` の先頭要素を削除する.
* `pop_back(t)`: 木 `t` の末尾要素を削除する.

## 計算量

* $O(\log n)$ 但し `build` と `dump` は $O(n)$