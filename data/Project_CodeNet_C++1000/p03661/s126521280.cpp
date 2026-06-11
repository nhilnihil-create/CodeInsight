#include <bits/stdc++.h>
using namespace std;
int main(){
 long  long int n,k[200000],sum=0;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>k[i];
    sum+=k[i];
  }
  
  long long int mon=2000000000,ss,snuke=0;
  for(int i=0;i<n-1;++i){
    snuke+=k[i];
    ss=sum-snuke*2;
    if(ss<0) ss*=-1;
    if(mon>ss) mon=ss;
  }
  cout<<mon<<endl;
}
