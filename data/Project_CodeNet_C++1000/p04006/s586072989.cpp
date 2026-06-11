#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
//#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define elif else if
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mp make_pair
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
#define ALL(a) (a).begin(),(a).end()
const int MOD = 1e9+7;
const ll INF =1e18;

int main(){
  ll n, x;cin>>n>>x;
  ll a[n];
  fr(i,n) cin>>a[i];
  ll ans = INF;
  ll b[n][n];
  fr(i,n)b[0][i] = a[i];
  fr(j,n){
    fr(i,n-1){
      b[i+1][j] = min(b[i][j],a[(j-i-1+n)%n]);
    }
  }
  fr(k,n){
    ll p = k*x;
    fr(i,n)p += b[k][i];
    ans = min(ans,p);
  }
  cout << ans << endl;
}