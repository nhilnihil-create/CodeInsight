#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  map<int64_t,int64_t>a;
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(a.count(tmp))a.at(tmp)++;
    else a[tmp]=1;
  }
  vector<int64_t>aa;
  for(auto num:a){
    if(num.second<=3&&num.second>=2){
      aa.push_back(num.first);
    }
    else if(num.second>=4){
      aa.push_back(num.first);
      aa.push_back(num.first);
    }
  }
  sort(aa.rbegin(),aa.rend());
  if(aa.size()<2){
    cout <<0<<endl;
    return 0;
  }
  cout <<aa.at(0)*aa.at(1)<<endl;
}