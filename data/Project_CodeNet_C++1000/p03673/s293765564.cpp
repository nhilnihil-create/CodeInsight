#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;

int main(){
    cin>>n;
    vector<int> a(n),ans(1);
    rep(i,0,n) cin>>a[i];
    if(n%2==0){
        ans[0]=a[0];
        rep(i,1,n){
            if(i%2!=0) ans.insert(ans.begin(),a[i]);
            else ans.insert(ans.end(),a[i]);
        }
    }
    else{
        ans[0]=a[0];
        rep(i,1,n){
            if(i%2!=0) ans.insert(ans.end(),a[i]);
            else ans.insert(ans.begin(),a[i]);
        }
    }
    rep(i,0,n) cout<<ans[i]<<" ";
    return 0;
}
