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
ll mt[111111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n),B(n);
  ll maa=0,mab=0;
  for(auto &a:A){cin>>a;maa = max(maa,a);}
  for(auto &a:B){cin>>a;mab = max(mab,a);}
  if(maa != mab){
    cout<<0<<endl;
    return 0;
  }
  mt[0] = A[0];
  for(int i=1;i<n;i++){
    if(A[i] != A[i-1])
      mt[i] = A[i];
  }
  if(mt[n-1] && mt[n-1] != B[n-1]){
    cout<<0<<endl;
    return 0;
  }
  mt[n-1] = B[n-1];
  for(int i=n-2;i>=0;i--){
    if(mt[i]){
      if(B[i] < mt[i]){
	cout<<0<<endl;
	return 0;
      }
    }
    if(B[i]!=B[i+1]){
      if(mt[i] && mt[i] != B[i]){
	cout<<0<<endl;
	return 0;
      }
      mt[i] = B[i];
    }
  }

  ll ret = 1;
  for(int i=0;i<n;i++){
    if(mt[i])continue;
    ret *= min(A[i],B[i]);
    ret %= MOD;
  }

  cout<<ret<<endl;
  return 0;
}
