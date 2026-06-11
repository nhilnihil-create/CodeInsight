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
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
ll n,c,k;
vi A;
bool check(ll mid){
  ll mi = llINF;
  ll cnt = 0;
  ll ho = 0;
  for(int i=0;i<n;i++){
    if(mi == llINF){
      mi = A[i];
      cnt++;
    }else{
      if(mi+k < A[i]){
	cnt = 1;
	mi = A[i];
	ho++;
      }else{
	cnt++;
      }
    }
    if(cnt == c){
      mi = llINF;
      ho++;
      cnt = 0;
    }
  }
  if(cnt)ho++;
  return ho <= mid;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>c>>k;
  A.resize(n);
  for(auto &a:A)cin>>a;
  ll le = 0,ri=111111;
  sort(ALL(A));
  while(ri-le > 1){
    ll mid = (ri+le)/2;
    if(check(mid)){
      ri = mid;
    }else{
      le = mid;
    }
  }
  cout<<ri<<endl;
  return 0;
}

