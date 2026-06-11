#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M (ll)1000000007
#define MM (ll) 1e8
#define INF (ll) 1e18
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
// using ll = long long;


int main(){
    ll n;
    ll m;
    cin >> n >> m;
    ll aX[n], aY[n];
    ll bX[m], bY[m];
    rep(i, n){
        cin >> aX[i] >> aY[i];
    }

    rep(i, m){
        cin >> bX[i] >> bY[i];
    }

    ll res[n];

    rep(i, n){
        ll minD = INF;
        rep(j, m){
            ll dist = abs(aX[i] - bX[j]) + abs(aY[i] - bY[j]);
            if(dist < minD){
                minD = dist;
                res[i] = j + 1;
            }
        }
    }

    rep(i, n){
        cout << res[i] << endl;
    }

}