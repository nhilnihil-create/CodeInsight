#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int main() {
  vll a(7);
  repeat(i,7) cin >> a[i];
  ll K = a[1];
  if(1&a[0]&a[3]&a[4]||!(1&(a[0]|a[3]|a[4]))){
    K += a[0]+a[3]+a[4];
  }else if(1&(a[0]^a[3]^a[4])){
    K += a[0]+a[3]+a[4]-1;
  }else if(!(a[0]*a[3]*a[4])){
    K += a[0]+a[3]+a[4]-2;
  }else{
    K += a[0]+a[3]+a[4]-1;
  }
  cout << K << endl;
  return 0;
}
