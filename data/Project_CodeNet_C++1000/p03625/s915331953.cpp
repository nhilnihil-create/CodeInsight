#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  map<long long,long long>mp;
  for(long long i=0;i<n;i++){
    long long x;
    cin>>x;
    x*=-1;
    if(mp.count(x))mp.at(x)++;
    else mp[x]=1;
  }
  long long tate=0;
  long long yoko=0;
  long long kotae=0;
  auto begin=mp.begin(),end=mp.end();
  for(auto iter=begin;iter!=end;iter++){
    if(iter->second >=2 && tate==0){
      tate=iter->first;
      mp[iter->first]-=2;
    }
    if(iter->second >=2 && tate!=0 && yoko==0){
      yoko=iter->first;
    }
    if(tate!=0&&yoko!=0)break;
  }
  kotae=tate*yoko;
  cout<<kotae<<endl; 
  return 0;
}