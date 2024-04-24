// Include{{{
#include "atcoder/segtree.hpp"
#include <atcoder/all>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// }}}

// Namespace{{{
using namespace std;
using namespace atcoder;
using namespace __gnu_pbds;
// }}}

// Macro{{{
#define rep3(i, a, b, c) for (auto i = a; i < b; i += c)
#define rep2(i, a, b) rep3(i, a, b, decltype(a){1})
#define rep1(i, a) rep2(i, decltype(a){0}, a)
#define overload3(a, b, c, d, e, ...) e
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; --i)
#define rrep1(i, a) rrep2(i, decltype(a){0}, a)
#define overload2(a, b, c, d, ...) d
#define rrep(...) overload2(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)
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

template <int M> auto &operator<<(ostream &os, const static_modint<M> &x) {
  return os << x.val();
}
template <class T> auto &operator<<(ostream &os, const vector<T> &v) {
  for (const auto &e : v)
    os << e << ' ';
  return os;
}
void put() { cout << endl; }
template <class T, class... U> void put(const T &a, const U &...b) {
  cout << a;
  if (sizeof...(b))
    cout << ' ';
  put(b...);
}
// }}}

// Input{{{
template <int M> auto &operator>>(istream &is, static_modint<M> &x) {
  int64_t val;
  is >> val;
  x = val;
  return is;
}
template <class T> auto &operator>>(istream &is, vector<T> &v) {
  for (auto &e : v)
    is >> e;
  return is;
}
#define input(type, ...)                                                       \
  type __VA_ARGS__;                                                            \
  read(__VA_ARGS__)
template <class... T> void read(T &...a) { (cin >> ... >> a); }
// }}}

// Utils{{{
template <class T> bool chmin(T &x, const T &y) {
  return y >= x ? false : (x = y, true);
}
template <class T> bool chmax(T &x, const T &y) {
  return y <= x ? false : (x = y, true);
}
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const char *Yes = "Yes", *No = "No", *YES = "YES", *NO = "NO";
const int INF = 1e9;
const int64_t LINF = 1e18;
// }}}

// Type{{{
using mint = modint998244353;
using ll = int64_t;
template <class T>
using sset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// }}}

// Multidimensional vector{{{
template <class T, int N, int i = 0>
auto make_vec(const int (&d)[N], const T &a) {
  if constexpr (i < N) {
    return vector(d[i], make_vec<T, N, i + 1>(d, a));
  } else {
    return a;
  }
}
template <class T, int N> auto make_vec(const int (&d)[N]) {
  return make_vec(d, T{});
}
// }}}

// IO Stream Config {{{
struct ios_config {
  ios_config() {
    cin.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(16);
  };
} ios_config;
// }}}

// Library {{{
vector<mint> fact, ifact;
void init_fact(int n) {
  fact.resize(n + 1), ifact.resize(n + 1), fact[0] = 1;
  rep(i, n) fact[i + 1] = fact[i] * (i + 1);
  ifact[n] = 1 / fact[n];
  rrep(i, n) ifact[i] = ifact[i + 1] * (i + 1);
}
mint C(int n, int r) {
  return n < 0 || r < 0 || n < r ? 0 : fact[n] * ifact[r] * ifact[n - r];
}
// }}}

int main() {
  // write codes here.
}

/* vim:set foldmethod=marker: */
