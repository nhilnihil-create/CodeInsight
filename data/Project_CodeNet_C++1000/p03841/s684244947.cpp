#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int x[n+1];
  int eve[1000000];
  fill(eve,eve+1000000,0);
  vector<pair<int,int>> v;
  for(int i=1;i<=n;i++){
    cin>>x[i];
    eve[x[i]]=i;
    v.push_back(make_pair(x[i],i));
  }
  sort(v.begin(),v.end());
  int now[n+1];
  fill(now,now+n+1,0);
  vector<int> ans;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].second-1;j++)ans.push_back(v[i].second);
  }
  for(int i=0;i<v.size();i++){
    for(int j=0;j<n-v[i].second;j++)ans.push_back(v[i].second);
  }
  //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
  for(int i=1;i<=n;i++){
    ans.insert(ans.begin()+v[i-1].first-1,v[i-1].second);
  }
  int cnt[n+1];
  fill(cnt,cnt+n+1,0);
  //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
  for(int i=0;i<ans.size();i++){
    if(eve[i+1]==0){
      cnt[ans[i]]++;
    }
    else{
      int u=eve[i+1];
      if(cnt[u]!=u-1){
        cout<<"No"<<endl;
        return 0;
      }
      cnt[u]++;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
  cout<<endl;
}