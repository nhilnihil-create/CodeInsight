#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;
 
/*---------------------------------------------------*/

int main(){
  ll h,w,n;
  int x,y;
  map<pair<int,int>,int> m;
  cin>>h>>w>>n;
  rep(i,n){
    cin>>y>>x;
    x--;y--;
    m[mp(x,y)]++;
    rep(i,8)if(1<=x+ddx[i]&&x+ddx[i]<w-1&&1<=y+ddy[i]&&y+ddy[i]<h-1)m[mp(x+ddx[i],y+ddy[i])]++;
  }
  map<int,ll> ans;
  for(auto itr : m){
    if(itr.first.first!=0&&itr.first.first!=w-1&&itr.first.second!=0&&itr.first.second!=h-1)ans[itr.second]++;
  }
  ll sum=0;
  REP(i,1,10){
    sum+=ans[i];
  }
  ans[0]=(h-2)*(w-2)-sum;
  rep(i,10){
    cout<<ans[i]<<endl;
  }
  return 0;
}
