#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
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
  lint N;
  bool check=true;
  cin >> N;
  lint A[N];
  //う　し　た　ぷ　に　き　あ　く　ん　笑
  rep(i,N) cin >> A[i];
  lint rem=((1+N)*N)/2;
  lint sum=accumulate(A,A+N,0LL);
  if(sum%rem!=0) check=false;
  lint ret=sum/rem;
  lint remmax[N]={};
  rep(i,N){
    remmax[i]=(ret-(A[(i+1)%N]-A[i]))/N;
    if((ret-(A[(i+1)%N]-A[i]))%N!=0) check=false;
    if(remmax[i]<0) check=false;
  }
  if(accumulate(remmax,remmax+N,0LL)!=ret) check=false;
  lint stone=0;
  rep(i,N) stone+=(N-i)*remmax[i];
  if(stone!=A[0]) check=false;
  for(int i=1;i<N;i++){
    stone+=ret-remmax[i-1]*N;
    if(stone!=A[i]) check=false;
  }
  if(check) cout << "YES" << endl;
  else cout << "NO" << endl;
}