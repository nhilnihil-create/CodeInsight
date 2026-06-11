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
  int i,j;
  int h,w;
  cin>>h>>w;
  vector< vector<string> > s(h,vector<string>(w));
  rep(i,h)rep(j,w)cin>>s[i][j];
  rep(i,h)rep(j,w)
    if(s[i][j]=="snuke"){
      char ans='A'+j;
      cout<<ans<<i+1<<endl;
      return 0;
    }
}
