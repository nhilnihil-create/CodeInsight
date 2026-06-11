#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int s=0,t=0;
  int n=S.size(),cnt=0;
  if(S[0]=='S') s++;
  for(int i=1;i<S.size();i++){
    if(S[i-1]=='T'&&S[i]=='S'){
      cnt+=min(s,t);
      s-=min(s,t)-1;t=0;
      continue;
    }
    if(S[i]=='T') t++;
    else s++;
  }
  cnt+=min(s,t);
  cout<<n-2*cnt<<endl;
}

