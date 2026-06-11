#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll N;cin>>N;
  vector<ll> A(N+1);rep(i,N) cin>>A[i];
  
  A[N]=1000000003;
  sort(A.begin(),A.end());
  
  ll count=1,ans=0;
  for(int i=0;i<N;i++){
	if(A[i]==A[i+1]) count++;
    else{
      if(count%2==0){
        count=1;
        continue;
      }
      else{
        count=1;
        ans++;
        continue;
      }
    }
  }
  
  cout << ans << endl;
}
 