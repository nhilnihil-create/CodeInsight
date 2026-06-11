#include<bits/stdc++.h>
using namespace std;
int par1[200001];
int par2[200001];
int len1[200001];
int len2[200001];
void init1(int n){
  for(int i=1;i<=n;i++){
    par1[i]=i;
    len1[i]=1;
  }
  return;
}
void init2(int n){
  for(int i=1;i<=n;i++){
    par2[i]=i;
    len2[i]=1;
  }
  return;
}
int root1(int n){
  if(par1[n]==n)return n;
  return root1(par1[n]);
}
int root2(int n){
  if(par2[n]==n)return n;
  return root2(par2[n]);
}
void unit1(int x,int y){
  x=root1(x);y=root1(y);
  if(x==y)return;
  if(len1[x]>len1[y]){
    par1[y]=x;
    len1[x]++;
  }
  else{
    par1[x]=y;
    len1[y]++;
  }
  return;
}
void unit2(int x,int y){
  x=root2(x);y=root2(y);
  if(x==y)return;
  if(len2[x]>len2[y]){
    par2[y]=x;
    len2[x]++;
  }
  else{
    par2[x]=y;
    len2[y]++;
  }
  return;
}
int main(){
  int n,k,l;cin>>n>>k>>l;
  int p[k],q[k],r[l],s[l];
  for(int i=0;i<k;i++)cin>>p[i]>>q[i];
  for(int i=0;i<l;i++)cin>>r[i]>>s[i];
  init1(n);init2(n);
  for(int i=0;i<k;i++){
    unit1(p[i],q[i]);
  }
  for(int i=0;i<l;i++){
    unit2(r[i],s[i]);
  }
  
  int ans[n+1];
  for(int i=1;i<=n;i++)ans[i]=0;
  vector<pair<pair<int,int>,int > >v={};
  for(int i=1;i<=n;i++){
    pair<int,int>p=make_pair(root1(i),root2(i));
    pair<pair<int,int>,int >pp=make_pair(p,i);
    v.push_back(pp);
  }
  sort(v.begin(),v.end()); 
  vector<int>w={};
  int cnt=0;
  for(int i=0;i<v.size()-1;i++){
    cnt++;
    if(v[i].first!=v[i+1].first){
      w.push_back(cnt);
      cnt=0;
    }
  }
  w.push_back(cnt+1);
  int cn=0;
  for(int i=0;i<v.size()-1;i++){
    ans[v[i].second]=w[cn];
    if(v[i].first!=v[i+1].first){
      cn++;
    }
  }
  ans[v[n-1].second]=w[w.size()-1];
  
  
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
