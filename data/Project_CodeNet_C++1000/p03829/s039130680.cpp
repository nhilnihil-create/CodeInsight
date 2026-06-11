#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll sum = 0;
    rep(i,n-1){
        sum += min((v[i+1]-v[i])*a,b);
    }
    cout << sum << endl;
    return 0;
}