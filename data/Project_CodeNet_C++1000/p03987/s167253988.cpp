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
typedef unsigned long long int ull;
typedef long long lint;
 
int main(void){
  int N;
  lint ans=0;
  cin >> N;
  lint a[N];
  rep(i,N) cin >> a[i];
  rep(i,N) a[i]--;
  lint place[N];
  rep(i,N) place[a[i]]=i;
  set<lint> save{-1,N};
  rep(i,N){
    lint now=place[i];
    lint l,r;
    auto tmp=save.lower_bound(now);
    r=*tmp;
    tmp--;
    l=*tmp;
    ans+=(i+1)*(r-now)*(now-l);
    save.insert(now);
  }
  cout << ans << endl;
}