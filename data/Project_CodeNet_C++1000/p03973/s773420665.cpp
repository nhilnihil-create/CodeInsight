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
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

int main(){
  ll N;cin >> N;
  vll A(N);
  repeat(i,N){
    cin >> A[i];
  }
  ll ans = 0;
  ll maxA = 0;
  repeat(i,N){
    ans += (A[i]-1)/(maxA+1);
    if(i==0||A[i] == maxA+1){
      maxA++;
    }
  }
  cout << ans << endl;
  return 0;
}
