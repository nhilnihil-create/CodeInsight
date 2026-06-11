#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
unordered_map<ll,int> dict;

int main(){
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
        dict[a[i]]++;
    }
    int ans=0;
    rep(i,0,n){
        if(dict[a[i]]%2==1){
        ans++;
        dict[a[i]]=0;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
