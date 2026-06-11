#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  long long cnt;
  map<char,long long>mp;
  
  for(int i=0;i<S.size();i++){
    mp[S.at(i)]++;
  }
  
  cnt=(S.size()*(S.size()-1))/2;
  //cout<<cnt<<endl;
  
  if(mp.size()==1){
    cout<<1<<endl;
    return 0;
  }
  
  for(auto itr=mp.begin();itr != mp.end();itr++){
    cnt-=(itr->second)*((itr->second)-1)/2;
    //cout<<(itr->second)*((itr->second)-1)/2<<endl;
  }
  cnt++;
  cout<<setprecision(20)<<cnt<<endl;
  return 0;
}
  