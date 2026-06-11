#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<pair<ll,ll>> p(n),p1(m); 
    rep(i,n){
        cin>>p[i].first>>p[i].second;
    }
    rep(i,m){
        cin>>p1[i].first>>p1[i].second;
    }
    rep(i,n){
        ll buf=1e10;
        int buf1=-1;
        rep(j,m){
            ll x=p[i].first,nx=p1[j].first,y=p[i].second,ny=p1[j].second;
            ll buf2=abs(x-nx)+abs(y-ny);
            if(chmin(buf,buf2)) buf1=j;
        }
        cout<<buf1+1<<endl;
    }
}