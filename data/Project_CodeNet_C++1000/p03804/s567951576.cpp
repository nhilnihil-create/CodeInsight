#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    
    int n, m;   cin >> n >> m;
    vector<vector<char>> g1(n, vector<char>(n)), g2(m, vector<char>(m));

    REP(i, n) REP(j, n) cin >> g1[i][j];
    REP(i, m) REP(j, m) cin >> g2[i][j];

    string ans="No";
    REP(i, n-m+1){
        REP(j, n-m+1){
            bool flag=true;
            FOR(p, i, i+m){ 
                FOR(q, j, j+m){
                    if(g1[p][q]==g2[p-i][q-j]) continue;
                    flag = false;
                }
            }
            if(flag) ans = "Yes";
        }
    }
    cout << ans << endl;

}