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
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
ll n;
vi A;
bool check(ll mid){
  ll now = A[mid];
  for(int i=0;i<mid;i++){
    now += A[i];
  }
  for(int i=mid+1;i<n;i++){
    if(now*2 < A[i])return false;
    now += A[i];
  }
  return true;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  A.resize(n);
  for(auto &a:A)cin>>a;
  sort(ALL(A));
  ll le = -1,ri = n-1;
  while(ri-le > 1){
    ll mid = (ri+le)/2;
    if(check(mid)){
      ri = mid;
    }else{
      le = mid;
    }
  }
  cout<<n-ri<<endl;
  return 0;
}
