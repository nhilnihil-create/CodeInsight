#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int r[200001]={0},d[200001]={0};
vector<int> A[200001];
int search1(int x){
  r[x]=1;
  for(auto i:A[x]) if(!r[i]) d[i]=d[x]+1,search1(i);
}
int search2(int x){
  r[x]=1;
  for(auto i:A[x]) if(!r[i]&&d[x]-1==d[i]) search2(i);
}
int main(){
    int n,a,b,B[200001],ans=0;
    cin>>n;
    rep(i,n-1) cin>>a>>b,A[a].push_back(b),A[b].push_back(a);
    search1(1);
    rep(i,n) r[i+1]=0;
    search2(n);
    rep(i,n) if(r[i+1]) B[d[i+1]]=i+1;
    rep(i,n) r[i+1]=0;
    rep(i,d[n]/2+1) r[B[i]]=1;
    search1(n);
    rep(i,n) if(r[i+1]) ans++;
    if(ans-d[n]/2-1>=(n+1)/2) cout<<"Snuke";
    else cout<<"Fennec";
}