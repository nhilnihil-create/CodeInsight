#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n,now,next,ans=0;cin>>n;
  vector<int> x(n,0);
  REP(i,n) cin>>x.at(i);
  sort(x.begin(),x.end());
  now=x.at(0);
  REP(i,n-1){
    next=x.at(i+1);
    if(now==next) ans++;
    now=next;
  }

  cout<<n-2*((ans+1)/2)<<endl;
}