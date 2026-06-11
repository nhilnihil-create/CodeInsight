#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
  int n,m;
  cin >> n >> m;
  vint a(n);
  repeat(i,n){
    cin >> a[i];
    a[i]--;
  }
  vll v(2*m+1,0);
  ll L=0;
  repeat(i,n-1){
    int r=a[i+1],l=a[i];
    if(r<l)r+=m;
    L+=r-l;
    v[l+2]-=1;
    v[r+1]+=1+r-l-1;
    v[r+2]-=r-l-1;
  }
  //debugArray(v,2*m);
  repeat(i,2*m){
    v[i+1] += v[i];
  }
  //debugArray(v,2*m);
  repeat(i,2*m){
    v[i+1] += v[i];
  }
  ll tmp=0;
  repeat(i,m){
    v[i] += v[i+m];
    tmp = min(tmp,v[i]);
  }
  debugArray(v,m);
  cout << L+tmp << endl;
  return 0;
}
