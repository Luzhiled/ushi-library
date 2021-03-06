#define PROBLEM "https://judge.yosupo.jp/problem/tree_decomposition_width_2"

#include "../../template/template.cpp"

#include "../../other/scanner.cpp"
#include "../../other/printer.cpp"

#include "../../structure/union-find/union-find.cpp"

#include "../../graph/others/tree-decomposition.hpp"

int main() {
  string x;
  int N, M;
  Scanner pin(stdin);
  Printer pout(stdout);
  pin.read(x, x, N, M);
  vector< int > A(M), B(M);
  UnionFind uf(N);
  for(int i = 0; i < M; i++) {
    pin.read(A[i], B[i]);
    --A[i], --B[i];
    uf.unite(A[i], B[i]);
  }
  int root = -1;
  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) {
      if(root == -1) {
        root = i;
      } else {
        A.emplace_back(root);
        B.emplace_back(i);
      }
    }
  }
  TreeDecomposition td(N);
  for(size_t i = 0; i < A.size(); i++) {
    td.add_edge(A[i], B[i]);
  }
  auto tap = td.build();
  if(tap.empty()) {
    pout.writeln("-1");
    return 0;
  }
  pout.writeln("s", "td", tap.size(), 2, N);
  for(size_t i = 0; i < tap.size(); i++) {
    for(auto &t : tap[i].bag) ++t;
    pout.writeln("b", i + 1, tap[i].bag);
  }
  for(size_t i = 0; i < tap.size(); i++) {
    for(auto &t : tap[i].child) pout.writeln(i + 1, t + 1);
  }
}
