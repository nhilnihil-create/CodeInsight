#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  map<int,int>mp;
  for(int i=0;i<n;i++){
    if(mp.count(a[i]))mp.at(a[i])++;
    else mp[a[i]]=1;
    if(mp.count(a[i]-1))mp.at(a[i]-1)++;
    else mp[a[i]-1]=1;
    if(mp.count(a[i]+1))mp.at(a[i]+1)++;
    else mp[a[i]+1]=1;
  }
  int saidai=0;
  auto begin=mp.begin(),end=mp.end();
  for(auto iter=begin;iter!=end;iter++){
    int tmp=iter->second;
    //cout<<tmp<<endl;
    saidai=max(saidai,tmp);
  }
  cout<<saidai<<endl;
  return 0;
}
