#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
using namespace std;

int main(){ 
  int n,x=0,y=0,ans=100000,c=0;
  cin>>n;
  int a[2*n];
  rep(i,0,2*n) cin>>a[i];
  sort(a,a+2*n);
  rep(i,0,n){
    c+=a[2*i];
  }
  co(c);
  
  return 0;
}