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
    cin >> N;
    vector<ll> ans(N);
    map<ll,pair<ll,ll>> mp;
    rep(i,N){
        ll a;
        cin >> a;
        if(!mp.count(a))mp[a].first = i;
        mp[a].second++;
    }

    ll total = 0; // 出現回数的な？
    ll minv = N; // 一番左のindex

    for(auto itr = mp.rbegin();itr != mp.rend();itr++){
        // 一番大きい山から見ていく感じ

        auto v = *itr;
        // v.second = pair<ll,ll> で v.second.first = index
        // v.second.second は出現回数
        auto it2 = itr;
        it2++;
        // 次に小さい山を調べる
        ll prev;
        if(it2 == mp.rend()) prev = 0;
        // もしもitrが一番小さい山だったら 次に小さい山のサイズは0にする
        else prev = it2->first;
        // そうじゃない場合は次に小さい山の大きさをprevにセットする

        total += v.second.second;
        // 個数をv.second.second個足す
        minv = min(minv,v.second.first);
        // 現時点で一番index番号が小さい場所を探す
        ans[minv] += total * (v.first - prev);
        // 現時点で一番index番号が小さい場所を基準として
        // 次に小さい山と同じサイズになるまで山をカットする
    }
    for(int i=0;i<N;i++)cout << ans[i] << endl;
}
