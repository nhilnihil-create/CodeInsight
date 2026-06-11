#include<bits/stdc++.h>
using namespace std;
int a[100010];
int sum[100010];
int cnt[100010];
vector<int> w[100010];
int dfs(int now){
  if(w[now].size()==0)return 0;
  int ret=0;
  vector<int> p;
  int yy=w[now].size();
  int mi=1000000000;
  for(int i=0;i<w[now].size();i++){
    int u=dfs(w[now][i]);
    p.push_back(u);
  }
  sort(p.begin(),p.end());
  for(int i=0;i<p.size();i++)ret=max(ret,p[i]+yy-i);
  return ret;
}
int main(){
  int n;cin>>n;
  fill(cnt,cnt+n+1,0);
  for(int i=2;i<=n;i++){
    cin>>a[i];
    cnt[a[i]]++;
    w[a[i]].push_back(i);
  }
  vector<int> v;
  for(int i=1;i<=n;i++){
    if(cnt[i]==0)v.push_back(i);
  }
  fill(sum,sum+n+1,0);
  int ans=dfs(1);
  cout<<ans<<endl;
}