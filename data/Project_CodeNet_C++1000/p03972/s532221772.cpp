#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
vector<pair<ll,ll>> V;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    int W,H,x;
    cin >> W >> H;
    rep(i,W)cin >> x,V.push_back({x,0});
    rep(i,H)cin >> x,V.push_back({x,1});
    sort(ALL(V));
    ll ans = 0;
    W++;
    H++;
    for(auto r:V){
        if(r.second==1)ans += W*r.first,H--;
        else ans += H*r.first,W--;
    }
    cout << ans << endl;
}