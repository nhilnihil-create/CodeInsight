#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

ll n,m,q,a[100010],b[100010],v[100010],d[100010],c[100010],f[100010]={};
bool al[100010][11]={};
vector<ll> t[100010];

void nuri(ll v,ll d,ll c){
  if(al[v][d]>0) return;
  fr(i,d+1) al[v][i]=1;
  if(f[v]==0) f[v]=c;
  if(d>0){
    for(auto i=t[v].begin();i!=t[v].end();i++){
      nuri(*i,d-1,c);
    }
  }
  return;
}

int main(){
  cin>>n>>m;
  fr(i,m){
    cin>>a[i]>>b[i];
    t[--a[i]].push_back(--b[i]);
    t[b[i]].push_back(a[i]);
  }
  cin>>q;
  fr(i,q) cin>>v[q-1-i]>>d[q-1-i]>>c[q-1-i];
  fr(i,q) nuri(--v[i],d[i],c[i]);
  fr(i,n) cout<<f[i]<<endl;
}