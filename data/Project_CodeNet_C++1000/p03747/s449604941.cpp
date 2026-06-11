#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N,L,T;
    cin >> N >> L >> T;
    vector<ll> X(N),W(N);
    rep(i,N){
        cin >> X[i] >> W[i];
    }
    vector<ll> tmp;
    // まずはありの最終的な座標を出す
    rep(i,N){
        if(W[i]==1)tmp.push_back((X[i] + T) % L);
        else tmp.push_back((((X[i]-T)%L)+L)%L);
    }
    sort(ALL(tmp));
    // 次に原点から見て一番近い所のindexを探す
    ll cnt = 0;
    rep(i,N){
        // ありさんが原点を右から左に通過するときは cnt++;
        // 左から右に通過するときは cnt--;
        // 現在地がX[i] で T 秒間にどれだけ原点を通るかを出したい
        if(W[i]==1){
            cnt += (T+X[i])/L;
        }else{
            cnt -= (T+L-X[i]-1)/L;
        }
    }
    cnt = ((cnt%N)+N)%N;
    vector<ll> res(N);
    rep(i,N) cout << tmp[(i+cnt)%N] << endl;
}
