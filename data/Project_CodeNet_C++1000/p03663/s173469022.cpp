#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

ll TEST_ANS;

bool compare(ll A, ll B) {
  string Astr = to_string(A);
  string Bstr = to_string(B);

  return (A <= B) == (Astr <= Bstr);
}

int query(ll X) {
  printf("? %lld\n", X);
  fflush(stdout);

#ifndef LOCAL
  char res[10];
  scanf("%s", res);
  return res[0] == 'Y';
#else
  return compare(X, TEST_ANS);
#endif
}

void answer(ll X) {
  printf("! %lld\n", X);
  fflush(stdout);
#ifdef LOCAL
  puts(TEST_ANS == X ? "AC!" : "WA.");
#endif
}

int main() {
  ll MAX_N = 1000000000;

#ifdef LOCAL
  scanf("%lld", &TEST_ANS);
#endif

  bool onezero = query(MAX_N * 10);

  if (onezero) {
    ll ans = 1;
    while(1) {
      bool p = query(ans * 10 - 1);
      if (p) {
        answer(ans);
        return 0;
      }
      ans *= 10;
    }
  } else {
    ll digits = 0, ans = 1;

    while(1) {
      bool p = query(ans * 10);
      if (!p) {
        break;
      }
      digits++;
      ans *= 10;
    }

    ll l = ans, r = ans * 10 -1;

    while(l < r) {
      ll mid = (l + r) /2;

      if (query(mid * 10)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    answer(l);
  }

  return 0;
}
