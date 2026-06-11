#include <bits/stdc++.h>
using namespace std;

int MOD=1000000007;
 
int main() {
  int N;
  string S,A;
  cin >> N >> S >> A;
  long long ans;
  int i=0;
  bool cur;
  if (S[0]==S[1]){
    ans=6;
    i++;
    cur=true;
  }
  else {
    ans=3;
    cur=false;
  }
  S+='0';
  while (i<N-1){
    if (S[i+1]!=S[i+2]&&!cur){
      ans=ans*2%MOD;
      i++;
      cur=false;
    }
    else if (S[i+1]==S[i+2]&&!cur){
      ans=ans*2%MOD;
      i+=2;
      cur=true;
    }
    else if (S[i+1]!=S[i+2]&&cur){
      i++;
      cur=false;
    }
    else if (S[i+1]==S[i+2]&&cur){
      ans=ans*3%MOD;
      cur=true;
      i+=2;
    }
  }
  cout << ans << endl;
}