#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v[100000];
ll n,a[100000];
ll c[100000];
bool ans=1;

ll dfs(int p,int pr){
  if(v[p].size()==1&&pr!=-1)return a[p];
  
  vector<ll> vv;
  for(int i=0;i<v[p].size();i++){
    int np=v[p][i];
    if(np!=pr)vv.push_back(dfs(np,p));
  }

  ll s=0,mx=0;
  for(int i=0;i<vv.size();i++)s+=vv[i],mx=max(mx,vv[i]);

  ll x=s-a[p];
  ll m;
  if(s>=mx*2)m=s/2;
  else m=s-mx;
  if(x>m||x<0)ans=0;

  if(pr==-1){
    if(s!=a[p])ans=0;
  }
  
  return s-2*x;
}


int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0,a,b;i<n-1;i++){
    cin>>a>>b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int m=0;
  for(int i=0;i<n;i++)
    if(v[i].size()==1)m=i;
    
  dfs(m,-1);
  cout<<(ans?"YES":"NO")<<endl;
  return 0;
}
