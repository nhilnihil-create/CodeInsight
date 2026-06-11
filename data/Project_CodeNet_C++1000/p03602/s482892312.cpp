#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
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
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j,k;
  int n;
  cin>>n;
  vector<vi> a(n,vi(n)),b(n,vi(n,1));
  rep(i,n)rep(j,n)cin>>a[i][j];
  rep(k,n)rep(i,n)rep(j,n)if(k!=i && k!=j)
    if(a[i][j]>a[i][k]+a[k][j]){
      cout<<-1<<endl;
      return 0;
    }else if(a[i][j]==a[i][k]+a[k][j]){
      b[i][j]=0;
    }
  ll ans=0;
  rep(i,n)rep(j,i)if(b[i][j])ans+=a[i][j];
  cout<<ans<<endl;
}
