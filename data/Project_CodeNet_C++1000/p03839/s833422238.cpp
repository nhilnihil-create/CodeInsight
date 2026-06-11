#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
  lint N,K;
  cin >> N >> K;
  lint A[N];
  rep(i,N) cin >> A[i];
  lint ans=0;
  lint range=accumulate(A,A+K,0LL);
  lint other=0;
  for(int i=K;i<N;i++) if(A[i]>0) other+=A[i];
  ans=max(0LL,range)+other;
  for(int i=K;i<N;i++){
    range+=A[i]-A[i-K];
    if(A[i-K]>0) other+=A[i-K];
    if(A[i]>0) other-=A[i];
    ans=max(ans,max(0LL,range)+other);
  }
  cout << ans << endl;
}