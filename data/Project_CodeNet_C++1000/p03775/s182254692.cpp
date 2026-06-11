#include <bits/stdc++.h>
using namespace std;

int main(){
long long N,ans;
cin>>N;    
int rtN=sqrt(N);
  for(int i=1;i<=rtN;i++){
  if(N%i==0){
  ans=N/i;
   }
  }
int digit=0;
//AとBのうち
  while(ans>0){
ans=ans/10;
  digit++;
}
 
cout<<digit<<endl;
}
