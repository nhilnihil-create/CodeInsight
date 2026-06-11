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
  int N;
  cin >> N;
  lint A,B,C,D;
  cin >> A >> B >> C >> D;
  lint dis=B-A;
  lint maxi=C*(N-1);
  lint scase[N];
  rep(i,N) scase[i]=maxi-2*C*i;
  lint rangeplus[N],rangeminus[N];
  rep(i,N){
    rangeplus[i]=(D-C)*(N-1-i);
    rangeminus[i]=(D-C)*i;
  }
  bool ans=false;
  rep(i,N){
    lint dis2=scase[i]-dis;
    if(dis2==0) ans=true;
    if(dis2>0) if(rangeminus[i]>=dis2) ans=true;
    if(dis2<0) if(rangeplus[i]>=-dis2) ans=true;
  }
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}