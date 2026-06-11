// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (int i = 0; i < (n); ++i)

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

std::map<long long, long long> prime_factor(long long n) {
  std::map<long long, long long> ret;
  for(long long i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1; // if n is prime number.
  return ret;
}

int main() {
  ll N;
  cin >> N;
  std::map<long long, long long> numprimes;
  for (int j = 2; j<=N; ++j) {
    ll n = j;
    for(long long i = 2; i * i <= n; ++i) {
      while(n % i == 0) {
        numprimes[i]++;
        n /= i;
      }
    }
    if(n != 1) numprimes[n]++; // if n is prime number.
  }
  ll ans = 1;
  for (const auto numprime : numprimes){
    ans *= numprime.second + 1;
    ans %= MODA;
  }
  cout << ans << endl;
  return 0;
}