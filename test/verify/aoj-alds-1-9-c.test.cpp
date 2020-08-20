#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include "../../template/template.cpp"

#include "../../structure/heap/leftist-heap.cpp"

int main() {
  string s;
  LeftistHeap< int, false > que;
  auto root = que.make_root();
  while(cin >> s, s != "end") {
    if(s == "insert") {
      int x;
      cin >> x;
      root = que.push(root, x);
    } else {
      cout << root->key << "\n";
      root = que.pop(root);
    }
  }
}
