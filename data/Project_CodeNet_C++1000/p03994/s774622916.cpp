#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int n=S.size();
  int k;cin>>k;
  for(int i=0;i<n;i++){
    if(S[i]=='a') continue;
    if('z'-S[i]+1<=k){
      k-='z'-S[i]+1;
      S[i]='a';
    }
  }
  if(k>0){
    k%=26;
    S[n-1]+=k;
  }
  cout<<S<<endl;
}