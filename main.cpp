// Include{{{
#include <bits/stdc++.h>
#include <atcoder/all>
// }}}

// Namespace{{{
using namespace std;
using namespace atcoder;
// }}}

// Macro{{{
#define overload3(a, b, c, d, e, ...) e
#define rep3(i, a, b, c) for (auto i=a; i<b; i+=c)
#define rep2(i, a, b) rep3(i, a, b, decltype(a){1})
#define rep1(i, a) rep2(i, decltype(a){0}, a)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep(i, a) for (auto i=a-1; i>=decltype(a){0}; --i)
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
using fps = vector<mint>;
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

// Library {{{
vector<mint> fact;
void init_fact(int n) {
  fact.resize(n+1);
  fact[0]=1;
  rep(i, n) fact[i+1] = fact[i] * (i+1);
}
mint C(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fact[n] / (fact[r] * fact[n-r]);
}
mint bostan_mori(fps p, fps q, uint64_t k) {
  auto f = [&](fps a, bool odd) {
    fps b;
    rep(i, odd, ssize(a), 2) b.push_back(a[i]);
    return b;
  };
  while (k) {
    auto r = q;
    rep(i, 1, ssize(q), 2) r[i] *= -1;
    q = f(convolution(q, r), 0);
    p = f(convolution(p, r), k&1);
    k /= 2;
  }
  return p[0] / q[0];
}
// }}}

int main() {
}

/* vim:set foldmethod=marker: */
