#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n;
  long long t=0,a=0,ans=0;cin>>n>>t>>a;
  REP(i,n-1){
    long long tn,an,m;cin>>tn>>an;
    m=max((t+tn-1)/tn,(a+an-1)/an);
    t=tn*m;
    a=an*m;
  }
  cout<<t+a<<endl;;
}