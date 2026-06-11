#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s; int N=s.size();
  int64_t ans=1;
  map<char,int64_t>M;
  M[s.at(0)]=1;
  for(int i=1;i<N;i++){
  if(!M.count(s.at(i))){
  M[s.at(i)]=1;ans+=i;
  }else{
  ans+=(i-M.at(s.at(i)));
    M.at(s.at(i))++;
  }
  }cout<<ans<<endl;
    return 0;
}