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
  int N,K;
  cin>>N>>K;
  VL A(N);
  rep(i,N) cin>>A[i];
  VL L(N+1),R(N+1);
  rep(i,N) L[i+1]=L[i]+A[i]*(A[i]>0);
  rep(i,N) R[N-1-i]=R[N-i]+A[N-1-i]*(A[N-1-i]>0);
  ll sum=0;
  rep(i,K) sum+=A[i];
  ll ans=0;
  rep(i,N-K+1){
    ll tmp=L[i]+R[i+K];
    if(sum>0) tmp+=sum;
    ans=max(ans,tmp);
    sum=sum-A[i]+A[i+K];
  }
  cout<<ans<<endl;
}
