#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
const ll INF = ll(1e18)+5;

int main() {
    ll N,x;
    cin >> N >>x;
    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    vector<vector<ll>> mina(N);
    for(int i=0;i<N;i++){
        mina[i].resize(N);
        mina[i][0] =a[i];
    }
    vector<ll> chose(N,INF);
    ll maxX =0;
    for(int i=0;i<N;i++)for(int j=1;j<N;j++){
        mina[i][j] = min(mina[i][j-1],a[(i-j+N)%N]);
    }
    ll ans = INF;
    for(int j=0;j<N;j++){
        ll temp =j*x;
        for(int i=0;i<N;i++){
            temp += mina[i][j];
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;
 

    return 0;
}