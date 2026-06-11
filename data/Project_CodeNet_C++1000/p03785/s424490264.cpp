#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,C,K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    rep(i,N) cin >> T[i];
    sort(T.begin(),T.end());
    ll ans = 0;
    for(int i=0;i<N;i++){
        ll st = i;
        while(i<N && T[i]-T[st]<=K && i-st<C) i++;
        // whileを抜けた時点ではiは次のバスの先頭なので次ループに移る前に調整する
        i--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}