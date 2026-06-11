#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,sum=0,ans=0;cin>>n;
  lvector A(n,0);rep(i,n) cin>>A[i];
  rep(i,n) {
    if(A[i]!=0) sum+=A[i];
    else {
      ans+=sum/2;
      sum=0;
    }
  }
  ans+=sum/2;
  print(ans);
  return 0;
}