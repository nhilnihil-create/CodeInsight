#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pair<ll,ll>> v;
    int w,h;cin >> w >> h;
    for(int i=0;i<w;i++){
        ll p;cin >> p;
        v.push_back({p,0});
    }
    for(int i=0;i<h;i++){
        ll q;cin >> q;
        v.push_back({q,1});
    }
    sort(v.begin(),v.end());
    ll ans=0,r=h+1,c=w+1;
    for(int i=0;i<v.size();i++){
        if(!v[i].second){
            ans+=r*v[i].first;
            c--;
        }
        else{
            ans+=c*v[i].first;
            r--;
        }
    }
    cout << ans << endl;
}