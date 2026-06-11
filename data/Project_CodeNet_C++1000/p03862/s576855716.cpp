#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[100000];
LL X;
LL ans=0;

int main(){
 scanf("%d%lld",&N,&X);
 rep(i,N) scanf("%lld",&A[i]);

 if(A[0]>X){ ans+=A[0]-X; A[0]=X; }
 rep(i,N-1){
  if(A[i+1]+A[i]>X){
   ans += A[i]+A[i+1]-X;
   A[i+1] = X-A[i];
  }
 }

 printf("%lld\n",ans);

 return 0;
}


