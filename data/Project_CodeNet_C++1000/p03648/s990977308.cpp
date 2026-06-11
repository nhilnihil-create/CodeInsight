#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1LL<<60
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main(){
  ll n;
  cin >> n;
  cout << 50 << endl;
  ll a[50];
  REP(i, 50) a[i] = 49 + (n/50);
  n %= 50;
  REP(i, n){
    REP(j, 50){
      if(i == j) a[j] += 50;
      else a[j]--;
    }
  }
  REP(i, 50){
    cout << a[i];
    if(i == 49) cout << endl;
    else cout << " ";
  }
	return 0;
}
