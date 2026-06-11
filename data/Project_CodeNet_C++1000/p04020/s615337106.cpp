#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=0;

int main() {
  ll N;
  cin>>N;
  ll A[N];
  rep(i,N){
    cin>>A[i];
  }
  ll ans =0;
  for(int i=0;i<N;i++){
    ans+=A[i]/2;
    if(i==N-1){
      break;
    }
    if(A[i]%2==1&&A[i+1]!=0){
      ans+=1; A[i+1]--;
    }
  }
  cout<<ans;
}