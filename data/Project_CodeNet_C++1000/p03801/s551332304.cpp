#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vec A(n),ans(n,0);
    rep(i,n) cin>>A[i];
    map<int,int> B,num;
    set<int> C,D;
    rep(i,n){
        C.insert(-A[i]);
        num[A[i]]++;
        if(B[A[i]]==0) B[A[i]]=i+1;
        else B[A[i]]=min(B[A[i]],i+1);
    }
    ll c=0;
    for(auto itr=C.begin();itr!=C.end();itr++){
        c+=num[-*itr];
        D.insert(B[-*itr]-1);
        ll a=-*itr,b=0;
        itr++;
        if(itr!=C.end()) b=-*itr;
        itr--;
        ans[*D.begin()]+=(a-b)*c;
    }
    for(auto i:ans) cout<<i<<"\n";
}