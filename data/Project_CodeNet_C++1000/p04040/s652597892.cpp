#include<bits/stdc++.h>
using namespace std; 


typedef long long ll; 
const int mod=1e9+7; 
const int nax=2e5+5; 

int mul(int a, int b){
  return (ll)a*b%mod; 
}
void add_self(int &a, int b){
  a+=b; 
  if(a>= mod) a-=mod; 
}

int fac[nax], ifac[nax], inv[nax]; 
void init(){
  fac[0]=1; 
  for(int i=1;i<nax;i++){
    fac[i]=mul(fac[i-1],i); 
  }
  ifac[0]=ifac[1]=1;
  inv[1]=1; 
  for(int i=2;i<nax;i++){
    int q=mod/i, r=mod%i; 
    inv[i]=-1*mul(q,inv[r]);  
    add_self(inv[i],mod); 
    ifac[i]=mul(ifac[i-1],inv[i]); 
  }
}

int ways(int a, int b, int c, int d){
  if(a>c || b>d) return 0; 
  int rows=c-a, cols=d-b; 
  int ret=mul(fac[rows+cols],mul(ifac[rows],ifac[cols])); 
  return ret; 
}

int main(){
  int h,w,a,b; 
  cin>>h>>w>>a>>b; 
  init(); 
  int ans=0; 
  for(int i=1;i<=h-a;i++){
    if(i!=h-a)
      add_self(ans,mul(ways(1,1,i,b+1),ways(i,b+2,h,w))); 
    else 
      add_self(ans,mul(ways(1,1,i,b+1),ways(i,b+1,h,w))); 
  }
  cout<<ans<<endl; 
}