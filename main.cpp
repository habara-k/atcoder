// Include{{{
#include <bits/stdc++.h>
#include <atcoder/all>
// }}}

// Namespace{{{
using namespace std;
using namespace atcoder;
// }}}

// Macro{{{
#define rep2(i, a, b) for (auto i: views::iota(a, b))
#define rep1(i, a) rep2(i, decltype(a){0}, a)
#define overload2(a, b, c, d, ...) d
#define rep(...) overload2(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) begin(v), end(v)
// }}}

// Output{{{
#ifdef LOCAL
#include <cpp-dump/dump.hpp>
struct cpp_dump_config {
  cpp_dump_config() {
    CPP_DUMP_SET_OPTION(log_label_func, cpp_dump::log_label::filename());
  }
} cpp_dump_config;
#define dump(...) cpp_dump(__VA_ARGS__)
#else
#define dump(...)
#endif

template<int M> auto &operator<<(ostream &os, const static_modint<M> &x) {
  return os << x.val();
}
template<class T> auto &operator<<(ostream &os, const vector<T> &v) {
  for (const auto& e : v) os << e << ' ';
  return os;
}

void print() { cout << endl; }
template<class T, class... Ts> void print(const T &a, const Ts &...b) {
  cout << a;
  if (sizeof...(b)) cout << ' ';
  print(b...);
}
// }}}

// Input{{{
template<int M> auto &operator>>(istream &is, static_modint<M> &x) {
  int64_t val; is >> val;
  x = val;
  return is;
}
template<class T> auto &operator>>(istream &is, vector<T> &v) {
  for (auto& e : v) is >> e;
  return is;
}

#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

template<class... T> void read(T &...a) { (cin >> ... >> a); }
// }}}

// Utils{{{
template<class T> bool chmin(T &x, const T &y) {
  return y >= x ? false : (x = y, true);
}
template<class T> bool chmax(T &x, const T &y) {
  return y <= x ? false : (x = y, true);
}
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const char *Yes = "Yes", *No = "No", *YES = "YES", *NO = "NO";
const int inf = 1e9;
const int64_t linf = 1e18;
// }}}

// Type{{{
using mint = modint998244353;
using ll = int64_t;
// }}}

// Multidimensional vector{{{
template<class T, int N, int i=0>
auto make_vec(const int (&d)[N], const T &a) {
  if constexpr (i < N) {
    return vector(d[i], make_vec<T, N, i+1>(d, a));
  } else {
    return a;
  }
}
template<class T, int N>
auto make_vec(const int (&d)[N]) {
  return make_vec(d, T{});
}
// }}}

// IO Stream Config {{{
struct ios_config {
  ios_config() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  };
} ios_config;
// }}}

using fps = vector<mint>;

mint bostan_mori(fps p, fps q, uint64_t k) {
  if (k==0) return p[0] / q[0];
  auto n = bit_ceil(max(p.size(), q.size()));
  p.resize(2*n), butterfly(p);
  q.resize(2*n), butterfly(q);
  static const internal::fft_info<mint> info;
  auto doubling = [&](fps &a) {
    auto b = fps{begin(a), begin(a)+n};
    butterfly_inv(b);
    mint r = 1 / mint(n);
    rep(i, n) b[i] *= r, r *= info.root[bit_width(n)];
    butterfly(b);
    rep(i, n) a[i+n] = b[i];
  };
  auto lo = [&](fps &a) {
    butterfly_inv(a);
    a.resize(n/2), a.resize(n);
    butterfly(a);
  };
  vector<mint> r(n); r[0]=1;
  rep(i, n-1) r[i+1] = r[i]*info.irate2[countr_one(i)];
  for (;;) {
    while (k < n/2) lo(p), lo(q), n /= 2;
    if (k&1) {
      rep(i, n) p[i] = (p[2*i]*q[2*i+1] - p[2*i+1]*q[2*i]) * r[i];
    } else {
      rep(i, n) p[i] = p[2*i]*q[2*i+1] + p[2*i+1]*q[2*i];
    }
    rep(i, n) q[i] = q[2*i] * q[2*i+1] * 2;
    if ((k /= 2) == 0) break;
    doubling(p), doubling(q);
  }
  return (p[0]+p[1]) / (q[0]+q[1]);
}

int main() {
}

/* vim:set foldmethod=marker: */
