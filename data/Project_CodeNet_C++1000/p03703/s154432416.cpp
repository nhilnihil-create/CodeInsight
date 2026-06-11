#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N,K;
  cin>>N>>K;
  VL A(N+1);
  rep(i,N) cin>>A[i+1];
  rep(i,N) A[i+1]+=A[i]-K;
  VL B(N+1);
  rep(i,N+1) B[i]=A[i];
  sort(all(B));
  map<ll,int> M;
  ll tmp=1;
  M[B[0]]=tmp;
  rep(i,N){
    if(B[i+1]!=B[i]) tmp++;
    M[B[i+1]]=tmp;
  }
  rep(i,N+1) A[i]=M[A[i]];
  int size=1<<20;
  VL BIT(size);
  ll ans=0;
  rep(i,N+1){
    tmp=A[i];
    ll sum=0;
    do{
      sum+=BIT[tmp];
      tmp-=(tmp&(-tmp));
    }while(tmp>0);
    ans+=sum;
    tmp=A[i];
    do{
      BIT[tmp]++;
      tmp+=(tmp&(-tmp));
    }while(tmp<=size);
  }
  cout<<ans<<endl;
}