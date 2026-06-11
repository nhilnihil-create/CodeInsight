#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  ll N;cin >> N;
  vector<ll>A(N);
  ll sum=0;
  rep(i,N){
     ll a;cin >> a;
     sum+=a;
     A[i]=a;
  }
  ll ad=N*(N+1)/2;
  if(sum%ad!=0){
     cout << "NO" << endl;
     return 0;
  }
  ll op=sum/ad;
  ll k=0;
  rep(i,N){
     ll cur=op-(A[(i+1)%N]-A[i]);
     if(cur<0||cur%N!=0){
        cout << "NO" << endl;
        return 0;
     }
     k+=cur/N;
  }
  if(op==k){
     cout << "YES" << endl;
  }
  else{
     cout << "NO" << endl;
  }

  return 0;
}