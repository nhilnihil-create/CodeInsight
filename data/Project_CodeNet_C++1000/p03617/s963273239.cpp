#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
int main(){

  int Q,H,S,D;
  cin>>Q>>H>>S>>D;
  int N;
  cin>>N;
  ll checkQ=0;
  ll checkH=0;
  ll checkS=0;
  ll checkD=0;
  checkQ=Q*8;
  checkH=H*4;
  checkS=S*2;
  checkD=D;
  ll check2=min({checkQ,checkH,checkS,checkD});
  ll ans=0;
  while(N>=2){
  
    ans+=check2;
    N-=2;
  }
  if(N==1){
    
    checkQ=Q*4;
    checkH=H*2;
    checkS=S; 
    ll check1=min({checkQ,checkH,checkS});
    ans+=check1;
  }
  cout<<ans;
  return 0;
}