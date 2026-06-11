#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(111111);
  while(n--){
    ll a,b;cin>>a>>b;
    A[a]++;A[b+1]--;
  }
  ll ans = 0;
  for(int i=0;i<111110;i++){
    A[i+1] += A[i];
    ans += (A[i+1] > 0);
  }
  cout<<ans<<endl;
  return 0;
}
