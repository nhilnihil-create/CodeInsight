// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

template<typename T>
T powint (const T& x, const T& y) {
  T ret = 1;
  for(int i=0; i<y; ++i) ret *= x;
  return ret;
}

long long factorial(long long X) {
  long long ans = 1;
  for(int i=1; i<X+1 ; ++i) ans *= i;
  return ans;
}

long long combination(long long n, long long r) {
  long long ans = 1;
  // for (long long i = n; i > (n-r); --i) ans *= i;
  for (long long i = 1; i <= r; ++i) {
    ans *= n+1-i;
    ans /= i;
  }
  return ans;
}

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  rep(i, N) cin >> v[i];

  sort(v.begin(), v.end(), greater<ll>());
  double maxave = 0.0;
  for (ll i = 0; i < A; ++i) {
    maxave += static_cast<double>(v[i]);
  }
  maxave /= static_cast<double>(A);
  ll count = 0;
  ll range = A-1;
  rep (i, N) {
    if (v[i] == v[A-1]) {
      count++;
      range = i;
    }
  }
  ll comb = 0;
  cerr << count <<" "<< range << endl;
  if(v[0] != v[A-1]) {
    comb += combination(count, count-(range-(A-1)));
    cerr << "a" << endl;
    // comb += factorial(count) /(factorial(count-(range-(A-1))) * factorial(range-(A-1)));
  }
  else if(range > B-1) {
    for (ll i = count-(range-(A-1)); i <= count-(range-(B-1)); ++i) {
      comb += combination(count, i);
      // comb += factorial(count) / (factorial(i) * factorial(count - i));
      cerr <<i<<" "<< comb << endl;
    }
  }
  else {
    for (ll i = count-(range-(A-1)); i <= count; ++i) {
      comb += combination(count, i);
      // comb += factorial(count) / (factorial(i) * factorial(count - i));
            cerr << i <<" "<< comb <<" "<< combination(count,i)<< endl;
    }
  }    
  cout << fixed << setprecision(16) << maxave << endl;
  cout << comb << endl;
  return 0;
}
