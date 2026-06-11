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
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,M;
  cin>>N>>M;
  VI A(M),B(M);
  rep(i,M) cin>>A[i]>>B[i];
  VI cnt(N+1);
  rep(i,M){
    cnt[A[i]]++;
    cnt[B[i]]++;
  }
  int ans=1;
  rep(i,N+1) if(cnt[i]%2) ans=0;
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}