
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n,m;
  cin>>n>>m;

  vector<ll> x(n+1),y(m+1);
  x[0]=y[0]=0;
  rep(i,n)cin>>x[i+1];
  rep(i,m)cin>>y[i+1];

  rep(i,n)x[i+1]+=1000000000;
  rep(i,m)y[i+1]+=1000000000;

  rep(i,n)x[i+1]+=x[i];
  rep(i,m)y[i+1]+=y[i];

  ll xsum=0,ysum=0;
  rep(i,n)(xsum+=i*(x[i+1]-x[i])-x[i])%=MOD;
  rep(i,m)(ysum+=i*(y[i+1]-y[i])-y[i])%=MOD;

  cout<<(xsum*ysum)%MOD<<endl;
}
