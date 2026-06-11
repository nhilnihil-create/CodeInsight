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
ll gcd(ll a,ll b){
  ll r = a%b;
  while(r > 0){
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;cin>>n>>k;
  vi A(n);
  ll now = -1;
  ll ma = 0;
  for(auto &a:A){
    cin>>a;
    ma = max(ma,a);
    if(now < 0)now = a;
    else now = gcd(now,a);
  }
  if(ma < k){cout<<"IMPOSSIBLE"<<endl;return 0;}
  for(int i=0;i<n;i++){
    if(abs(A[i]-k)%now == 0){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
