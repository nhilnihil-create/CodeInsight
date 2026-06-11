#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,L;
  cin>>N>>L;
  VL A(N);
  rep(i,N) cin>>A[i];
  int ans=-1;
  rep(i,N-1) if(A[i]+A[i+1]>=L){
    cout<<"Possible"<<endl;
    ans=i+1;
    break;
  }
  if(ans==-1){
    cout<<"Impossible"<<endl;
    return 0;
  }
  rep(i,ans-1) cout<<i+1<<endl;
  rep(i,N-1-ans) cout<<N-1-i<<endl;
  cout<<ans<<endl;
}