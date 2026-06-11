#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W,H; cin >> W >> H;
    vector<pair<ll,int>> R;
    for (int i=0;i<W;++i){
        ll p; cin >> p;
        R.emplace_back(p,0);
    }
    for (int i=0;i<H;++i){
        ll q; cin >> q;
        R.emplace_back(q,1);
    }
    sort(R.begin(),R.end());
    vector<ll> cnt(2);
    cnt[0]=W+1,cnt[1]=H+1;
    ll ans=0;
    for (int i=0;i<H+W;++i){
        ans+=cnt[R[i].second^1]*R[i].first;
        --cnt[R[i].second];
    }
    cout << ans << '\n';
}