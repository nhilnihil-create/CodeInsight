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
  int N;
  cin>>N;
  VI A(N);
  rep(i,N) cin>>A[i];
  sort(all(A));
  VL X(N);
  X[0]=A[0];
  rep(i,N-1) X[i+1]=X[i]+A[i+1];
  int ans=1;
  rep(i,N-1){
    if(A[N-1-i]>X[N-2-i]*2) break;
    ans++;
  }
  cout<<ans<<endl;
}