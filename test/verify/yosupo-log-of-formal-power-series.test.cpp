#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "../../template/template.cpp"

#include "../../math/combinatorics/mod-int.cpp"
#include "../../math/fft/number-theoretic-transform-friendly-mod-int.cpp"

#include "../../math/fps/log.cpp"

const int MOD = 998244353;
using mint = ModInt< MOD >;

int main() {
  NumberTheoreticTransformFriendlyModInt< mint > ntt;
  using FPS = FormalPowerSeries< mint >;
  FPS::set_mult([&](const FPS& a, const FPS& b) { return ntt.multiply(a, b);});
  FPS::set_fft([&](FPS &a) { ntt.ntt(a); }, [&](FPS &a) { ntt.intt(a); });

  int N;
  cin >> N;
  FPS F(N);
  cin >> F;
  cout << F.log() << endl;
}
