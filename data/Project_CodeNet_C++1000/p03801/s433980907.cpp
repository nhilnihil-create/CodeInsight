#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N ;
    vector<pair<ll,ll>> a(N+1);
    vector<ll> b(N+1);
    rep(i,N){
        cin >> a[i+1].first;
        a[i+1].second = i+1;
    }
    sort(ALL(a));
    ll t = 0;
    ll p1 = N + 1;
    for(ll i = N;i>0;i--){
        t += (ll)a[i].first;
        if(a[i].first != a[i-1].first){
            p1 = min(p1,a[i].second);
            b[p1] += t - (N+1-i)*(a[i-1].first);
            t = (N+1-i)*(a[i-1].first);
        }
    }
    for(int i=1;i<=N;i++)cout << b[i] << endl;
}