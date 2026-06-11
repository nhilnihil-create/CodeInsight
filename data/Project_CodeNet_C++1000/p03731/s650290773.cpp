#include <bits/stdc++.h>
#include <map> // pair
using namespace std;


int main(){
  int N,T,ans;
  cin>>N>>T;
  vector<int>t(N);
  ans = 0;
  for(int i=0;i<N;i++){
    cin>>t.at(i);
    if(i>0){
      if(t.at(i)-t.at(i-1)<T){
        ans+=t.at(i)-t.at(i-1);
      }else{
        ans+=T;
      }
    }
  }
  ans+=T;

  cout<<ans<<endl;

}
