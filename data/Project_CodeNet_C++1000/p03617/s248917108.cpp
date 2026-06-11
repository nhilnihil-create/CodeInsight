#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 int64_t Q,H,S,D,N;
 cin>>Q>>H>>S>>D>>N;
 if(min({4*Q,2*H,S,D/2})==4*Q){cout<<N*4*Q<<endl;}
 if(min({4*Q,2*H,S,D/2})==2*H){cout<<N*2*H<<endl;}
 if(min({4*Q,2*H,S,D/2})==S){cout<<N*S<<endl;}
 if(min({4*Q,2*H,S,D/2})==D/2){
   if(N%2==0){cout<<D*N/2<<endl;}
     else{cout<<D*(N/2)+min({4*Q,2*H,S})<<endl;}
 }
 return 0;}