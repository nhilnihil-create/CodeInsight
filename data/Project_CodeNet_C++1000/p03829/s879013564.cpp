#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
  int n;ll a,b,ans,now,next;cin>>n>>a>>b>>now; 
  REP(i,n-1){
    cin>>next;
    ans+=((next-now)*a<b?(next-now)*a:b);
    now=next;
  }
  cout<<ans<<endl;
}