#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
int main(void){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll x=-1,y=0;
    rep(i,n-1){
        if(a[i]!=a[i+1])continue;
        if(x==-1){
            x=a[i];
            i++;
            continue;
        }else{
            y=a[i];
            break;
        }
    }
    ll res=x*y;
    cout<<res<<endl;
}