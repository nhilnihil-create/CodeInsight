#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

void YN(bool x){
  if(x) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return;
}
int main() {
  bool finish=true;
  int H,W; cin>>H>>W;
  vector<int> S(26,0);
  rep(i,H*W){
    char a; cin>>a;
    int b=a-97;
    S.at(b)++;
  }
  int ki=0,ni=0,yon=0;
  rep(i,26){
    if(S.at(i)%4==0)yon++;
    else if(S.at(i)%2==0)ni++;
    else ki++;
  }
  
  if(ki>1) finish=false;
  else if(ki==1){
    if(H%2==1&&W%2==1){
      if(ki!=1)ni++;
      if(ni>(H-1)/2+(W-1)/2) finish=false;
    }
    else finish=false;
  }
  else{
    if(H%2==1&&W%2==1) finish=false;
    else if(H%2==0&&W%2==0&&ni>0) finish=false;
    else{
      if(H%2==1 && ni>W/2)finish=false;
      if(W%2==1 && ni>H/2)finish=false;
    }
  }
  YN(finish);
}

