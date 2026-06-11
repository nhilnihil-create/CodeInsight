#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,x;cin>>N>>x;
  if(x==1||x==2*N-1){cout<<"No";return 0;}
  cout<<"Yes"<<endl;
  
  if(N==2){cout<<1<<endl<<2<<endl<<3;return 0;}

  vector<long>A(2*N-1,-1);
  long s=(x<=N)*2-1;
  A[N-3]=x+2*s; //x+2<=2*N-1
  A[N-2]=x-1*s; // 
  A[N-1]=x;
  A[N]=x+1*s; 
  
  long p=0;
  for(long i=1;i<=2*N-1;i++){
    while(p<2*N-1&&A[p]!=-1)p++;
    if(i==x-1*s||i==x||i==x+1*s||i==x+2*s)continue;
    A[p]=i;
  } 
  for(long x:A)cout<<x<<endl;
}

