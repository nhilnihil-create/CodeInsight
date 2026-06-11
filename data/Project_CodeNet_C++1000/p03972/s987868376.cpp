#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int h,w; cin>>h>>w;
    vector<P> a(h+w);
    rep(i,h){
        cin>>a[i].first;
        a[i].second=0;
    }
    rep(i,w){
        cin>>a[i+h].first;
        a[i+h].second=1;
    }
    sort(all(a));

    int ans=0,vert=h+1,side=w+1;
    rep(i,h+w){
        if(a[i].second==0){
            ans+=a[i].first*side;
            vert--;
        }else{
            ans+=a[i].first*vert;
            side--;
        }
    }
    cout<<ans<<endl;
    

}