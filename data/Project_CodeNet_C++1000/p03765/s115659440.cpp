#include<bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  int as[100100], bs[100100];
  as[0]=bs[0]=0;
int x=s.size();
  for(int i=0;i<x;i++){
    if(s[i]=='A')as[i+1]=as[i]+1;
    else as[i+1]=as[i];
    if(s[i]=='B')bs[i+1]=bs[i]+1;
    else bs[i+1]=bs[i];
  }
  
  int at[100100],bt[100100];
  at[0]=bt[0]=0;
int y=t.size();
  for(int i=0;i<y;i++){
    if(t[i]=='A')at[i+1]=at[i]+1;
    else at[i+1]=at[i];
    if(t[i]=='B')bt[i+1]=bt[i]+1;
    else bt[i+1]=bt[i];
  }
  int q; cin>>q;
  for(int i=0;i<q;i++){
    int es,fs,et,ft;
    cin>>es>>fs>>et>>ft;
    int m,n,M,N;
    m=as[fs]-as[es-1];
    n=bs[fs]-bs[es-1];
    M=at[ft]-at[et-1];
    N=bt[ft]-bt[et-1];
    if((M-m+300000)%3==(N-n+300000)%3){
      cout<<"YES"<<endl;
    } else cout<<"NO"<<endl;
}
return 0;
}