
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

int h,w;

bool in(int x, int y){
  if(1<=x && x<h-1 && 1<=y && y<w-1) return true;
  else return false;
}

int main(void) {
  int i,j,k;
  int n;
  cin>>h>>w>>n;
  map<pii,int> mp;
  int d[3]={-1,0,1};
  rep(i,n){
    int a,b;
    cin>>a>>b;
    a--,b--;
    rep(j,3)rep(k,3)
      if(in(a+d[j],b+d[k]))mp[pii(a+d[j],b+d[k])]++;
  }

  vector<ll> ans(10,0);
  i=0;
  for(auto itr = mp.begin(); itr != mp.end(); ++itr){
    ans[itr->second]++;
  }

  ll sum=0;
  rep(i,10)sum+=ans[i];
  
  ans[0]=(ll)(h-2)*(w-2)-sum;

  rep(i,10)
    cout<<ans[i]<<endl;
}
