#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  vector<string> A={"SS","SW","WS","WW"};
  for(int j=0;j<4;j++){
    string T=A[j];
    for(int i=2;i<N;i++){
      if(T[i-1]=='S' && S[i-1]=='o')T+=T[i-2];
      else if(T[i-1]=='S')T+='S'+'W'-T[i-2];
      else if(S[i-1]=='o')T+='S'+'W'-T[i-2];
      else T+=T[i-2];
    }
    if(((T[N-1]=='S' && S[N-1]=='o') || (T[N-1]=='W' && S[N-1]=='x'))){
      if(T[N-2]!=T[0])continue;
    }else if(T[N-2]==T[0])continue;
    if(((T[0]=='S' && S[0]=='o') || (T[0]=='W' && S[0]=='x'))){
      if(T[N-1]!=T[1])continue;
    }else if(T[N-1]==T[1])continue;
    cout<<T<<endl;
    return 0;
  }
  puts("-1");
}