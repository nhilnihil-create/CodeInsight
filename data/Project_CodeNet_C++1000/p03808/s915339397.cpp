#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <stdio.h>

using namespace std;

#define REP(i,n,m) for( long long int i = (n); i < (m); i++ )
#define REV(v) for (auto itr = v.rbegin(); itr != v.rend(); itr++)
#define ll long long
#define ALL(a) (a).begin(), (a).end()
#define SORT(v) sort( ALL(v) );
#define LAST(v) v[v.size()-1]
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pi pair<int, int>
#define MP make_pair
#define PB push_back
#define IIN(a) int a; cin >> a;
#define LIN(a) ll a; cin >> a;
#define SIN(a) string a; cin >> a;
#define Vl(v,n) vector<ll> v(n);
#define Read_vll(v,n) vector<ll> v(n);REP(i,0,n)cin>>v[i];
#define EPS (1e-10)
#define INF 1000000000000LL

int MOD=1000000007;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
//I ASCII code: '0' = 48; 'A' = 65; 'a' = 97

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LIN(n)
    Read_vll(a,n)
    ll sum = 0,m = n * (n + 1) / 2;
    REP(i,0,n){
      sum += a[i];
    }

    if( sum % m != 0 ){
      cout << "NO" << endl;
      return 0;
    }

    m = sum / m;
    for( ll i = 0; i < n; i++ ){
      ll d = a[i] - ( i == 0 ? a[n - 1] : a[i - 1]);
      d -= m;
      if( d > 0 ){
        cout << "NO" << endl;
        return 0;
      }

      d = -d;
      if( d % n != 0 ){
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
    return 0;
}
