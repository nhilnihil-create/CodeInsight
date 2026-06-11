#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
  #include "header.h"
#else
  #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int n; cin>>n;
  vi a(n);
  rep(i,0,n) {
    cin>>a[i];
  }
  long long sum = 0;
  rep(i,0,n) sum += a[i];
  if(sum % ((n*1LL*(n+1))/2) != 0) {
    cout<<"NO"<<endl;
    return 0;
  }
  lli k = sum / ((n*1LL*(n+1))/2);
  debug(k);
  rep(i,0,n-1) {
    if((a[i]-a[i+1]+k)<0 || (a[i]-a[i+1]+k)%n != 0) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(((a[n-1]-a[0]+k)<0 || (a[n-1]-a[0]+k)%n != 0)) {
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
}

