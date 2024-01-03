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
#define rep1(i, a) rep2(i, 0, a)
#define overload2(a, b, c, d, ...) d
#define rep(...) overload2(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
// }}}

// Output{{{
template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p);
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v);
template<class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m);
template<class T>
ostream &operator<<(ostream &os, const set<T> &s);
template<int M>
ostream &operator<<(ostream &os, const static_modint<M> &x);

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ':' << p.second;
}
template<class Iterable> ostream &__print_all(ostream &os, const Iterable &v) {
  int a = 0;
  for (const auto& e : v) {
    if (a) os << ", ";
    os << e;
    a = 1;
  }
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  return __print_all(os << '[', v) << ']';
}
template<class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  return __print_all(os << '{', m) << '}';
}
template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  return __print_all(os << '{', s) << '}';
}
template<int M>
ostream &operator<<(ostream &os, const static_modint<M> &x) {
  return os << x.val();
}

void print() { cout << endl; }
template<class T, class... Ts> void print(const T &a, const Ts &...b) {
  cout << a;
  if (sizeof...(b)) cout << ' ';
  print(b...);
}

#ifdef LOCAL
void __dump() { cerr << endl; }
template<class T, class... Ts> void __dump(const T &a, const Ts &...b) {
  cerr << a;
  if (sizeof...(b)) cerr << ", ";
  __dump(b...);
}
#define dump(...) cerr << #__VA_ARGS__ << ": "; __dump(__VA_ARGS__);
#else
#define dump(...) void(0)
#endif

template<class T> void print_vec(const vector<T> &v) {
  for (const auto& e : v) {
    cout << e << ' ';
  }
  cout << endl;
}
// }}}

// Input{{{
template<class T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto& e : v) is >> e;
  return is;
}
template<int M> istream &operator>>(istream &is, static_modint<M> &x) {
  int64_t val; is >> val;
  x = val;
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
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const char *Yes = "Yes", *No = "No", *YES = "YES", *NO = "NO";
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

// Fast IO Stream{{{
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  };
} fast_ios_;
// }}}

int main() {
}

/* vim:set foldmethod=marker: */
