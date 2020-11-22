#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412"

#include "../../template/template.cpp"

#include "../../geometry/template.cpp"

int main() {
  int N, Q;
  cin >> N;
  Polygon g(N);
  cin >> g;
  cin >> Q;
  while(Q--) {
    double x, y;
    cin >> x >> y;
    Point p(x - x / 10000, y - y / 10000);
    if(convex_contains(g, p)) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
}
