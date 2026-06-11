#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
const ll mod2=1e9+9 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,n)cin>>a[i];
  ll ans=a[0]-1;
  int pos=2;
  rep(i,n-1){
    ans+=(a[i+1]-1)/pos;
    pos+=(a[i+1]==pos);
    }
  cout<<ans<<endl;
  return 0;
}
