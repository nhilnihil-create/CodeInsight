#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1LL << 30;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, n) for (ll i = a; i < n; i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll minRank=0,min=INF;
    REP(i,n){
        ll a,b;
        cin >> a >> b;
        if(minRank<a){
            minRank= a;
            min= b;
        }
    }
    cout << minRank+min << endl;
}