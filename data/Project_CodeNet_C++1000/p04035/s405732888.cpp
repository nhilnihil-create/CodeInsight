#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    ll tot=0;
    ll maxi=0;
    int y=-1;
    rep(i,n){
        cin>>a[i];
        tot+=a[i];
    }
    rep(i,n-1){
        ll buf=a[i]+a[i+1];
        if(chmax(maxi,buf))y=i;
    }
    if(maxi<x){
        cout<<"Impossible"<<endl;
        return 0;
    }
    vector<int> t;
    rep(i,y){
        t.push_back(i+1);
    }
    for(int i=n-1;i>y;i--){
        t.push_back(i);
    }
    cout<<"Possible"<<endl;
    rep(i,n-1){
        cout<<t[i]<<endl;
    }
}