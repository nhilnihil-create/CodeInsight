#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

void YN(bool x){
  if(x) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main() {
  vector<string> K={"maerd","remaerd","esare","resare"};
  bool finish=true;
  string S; cin>>S;
  int s=S.size();
  reverse(S.begin(),S.end());
  for(int i=0;i<s;i++){
    
    if(S[i]=='r'){
      if(i+1>s-1)finish=false;
      if(S[i+1]!='e') finish=false;
      if(S[i+2]=='m'){
        if(i+6>s-1) finish=false;
        rep(j,7) if(S[i+j]!=K[1][j])finish=false;
        i+=6;
      }
      else if(S[i+2]=='s'){
        if(i+5>s-1) finish=false;
        rep(j,6) if(S[i+j]!=K[3][j])finish=false;
        i+=5;
      }
      else finish=false;
    }
    
    else if(S[i]=='m'){
      if(i+4>s-1) finish=false;
      rep(j,5) if(S[i+j]!=K[0][j]) finish=false;
      i+=4;
    }
    
    else if(S[i]=='e'){
      if(i+4>s-1) finish=false;
      rep(j,5) if(S[i+j]!=K[2][j])finish=false;
      i+=4;
    }
    
    else finish=false;

    if(!finish) break;
    
  }
  YN(finish);
}
