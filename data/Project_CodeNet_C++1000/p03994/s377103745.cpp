#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;int K;cin>>K;
  for(int i=0;i<S.length();i++){
    if(S[i]=='a')continue;
    int a=26-(S[i]-97);
    if(a<=K){S[i]='a';K-=a;}
  }
  S[S.length()-1]=(S[S.length()-1]-97+K)%26+97;
  cout<<S;
}