#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int,greater<int>> a;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
  }
  vector<int> r;
  vector<int> s;
  for(auto x:a){
    if(x.second>=2)
      r.push_back(x.first);
    if(x.second>=4)
      s.push_back(x.first);
  }
  if(s.size()>=1){
    if(r.size()>=2)
      cout<<max((int64_t)s.at(0)*s.at(0),(int64_t)r.at(0)*r.at(1))<<endl;
    else
      cout<<(int64_t)s.at(0)*s.at(0)<<endl;
  }else{
    if(r.size()>=2)
      cout<<(int64_t)r.at(0)*r.at(1)<<endl;
    else
      cout<<0<<endl;
  }
}