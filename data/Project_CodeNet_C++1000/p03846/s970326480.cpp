#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());
  if(N%2==0){
    bool flag=true;
    ll ans=1;
    for(int i=0;i<N/2;i++){
      if(A.at(2*i)!=2*i+1||A.at(2*i+1)!=2*i+1){
        flag=false;
        break;
      }
      ans*=2;
      ans%=MOD;
    }
    if(flag){
      cout<<ans<<endl;
    }else{
      cout<<0<<endl;
    }
  }else{
    bool flag=true;
    ll ans=1;
    if(A.at(0)!=0){
      flag=false;
    }
    for(int i=0;i<(N-1)/2;i++){
      if(A.at(2*i+1)!=2*(i+1)||A.at(2*i+2)!=2*(i+1)){
        flag=false;
        break;
      }
      ans*=2;
      ans%=MOD;
    }
    if(flag){
      cout<<ans<<endl;
    }else{
      cout<<0<<endl;
    }
  }
}
