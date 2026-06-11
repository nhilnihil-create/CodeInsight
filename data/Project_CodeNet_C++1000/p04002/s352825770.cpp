#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll h,w,n,A[200000],B[200000],x[3]={-1,0,1},y[3]={-1,0,1},a,b,num[10]={0},sum=0;
    cin>>h>>w>>n;
    rep(i,n) cin>>A[i]>>B[i];
    map<pair<ll,ll>,ll> C;
    rep(i,n)rep(j,3)rep(k,3) C[make_pair(A[i]+x[j],B[i]+y[k])]++;
    for(auto i=C.begin();i!=C.end();++i){
        a=i->first.first,b=i->first.second;
        if(a>1&&a<h&&b>1&&b<w) num[i->second]++;
    }
    rep(i,10) sum+=num[i];
    cout<<(h-2)*(w-2)-sum<<endl;
    rep(i,9) cout<<num[i+1]<<endl;
}