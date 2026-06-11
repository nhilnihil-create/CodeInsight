#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

int main() {
  int n,k; cin>>n>>k;
  vector<ll> A(n);
  rep(i, n) cin>>A[i];
  ll res=1e12;

  rep(bit, (1<<n)) {
     int tmp=0;
     rep(i, n) {
       if (bit&(1<<i)) tmp++;
     }
     if (tmp!=k) continue;
     ll sum=0;
     ll minH=A[0];
     for (int i=1; i<n; i++) {
       minH=max(minH, A[i-1]);
       if (bit&(1<<i)) {
         if (minH>=A[i]) {
           sum+=minH-A[i]+1;
           minH++;
         }
       }
     }
     res=min(res, sum);
  }
  cout<<res<<endl;
}
