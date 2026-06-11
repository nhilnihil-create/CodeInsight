#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;
const int MOD = 1000000007;
const int MAX_N = 1<<18;
int N, dat[2*MAX_N -1];
void init(int m){
    N=1;
    while(N<m)N*=2;
    for(int i=0;i<2*N-1;i++)dat[i]=LLONG_MAX;
}
void update(int k,int a){
    k+=N-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}

int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return LLONG_MAX;
    if(a<=l&&r<=b)return dat[k];
    return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}
signed main() {
 int n,a;
 cin>>n;
 init(n);
 for(int i=0;i<n;i++){
   cin>>a;
   update(i,a);
 }
 //cerr<<'i';
 int ok,ng,mid,j,k,ans=0;
 for(int i=0;i<n;i++){
   ng=-1;ok=i;
   while(abs(ok-ng)>1){
     mid=(ok+ng)/2;
     if(query(mid,i+1,0,0,N)==dat[i+N-1])ok=mid;
     else ng=mid;
   }
   j=ok;
   ng=n;ok=i;
   while(abs(ok-ng)>1){
     mid=(ok+ng)/2;
     if(query(i,mid+1,0,0,N)==dat[i+N-1])ok=mid;
     else ng=mid;
   }
   k=ok;
   ans=(ans+dat[i+N-1]*(i-j+1)*(k-i+1));
  // cerr<<'i';
 }
 cout<<ans;

return 0;
}
