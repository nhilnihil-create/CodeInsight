#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define c(n) cin>>n
#define c2(n,m) cin>>n>>m
#define c3(n,m,k) cin>>n>>m>>k
#define c4(n,m,k,l) cin>>n>>m>>k>>l
#define co(n) cout<<n<<endl
using namespace std;

int main(){
  int a,b,c,d,e=1,n=1;
  c(a);
  while(n<a){
    e++;
    n+=e;
  }
  co(e);
  
  
  return 0;
}
