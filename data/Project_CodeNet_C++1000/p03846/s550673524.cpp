#include <bits/stdc++.h>
#define ull unsigned long long
#define mod 1000000007
using namespace std;

int exp_mod(int a, int b) {
  int res = 1;
  for(int i=0;i<b;i++) {
    res=(res*a)%mod;
  }
  // while(b) {
  //   if(b&1)
  //     res=(res*a)%mod;
  //   a=(a*a)%mod;
  //   b>>=1;
  // }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  int a[n];
  unordered_map<int,int> store;
  for(int i=0;i<n;i++) cin>>a[i],store[a[i]]++;
  int start = n-1;
  bool invalid = false;
  if(store[0]!=(n&1))
    invalid=true;
  if(!invalid) {
    while(start > 0) {
      if(store[start]!=2) {
        invalid=true;
        break;
      }
      start-=2;
    }
  }
  if(invalid)
    cout<<"0";
  else {
    cout<<exp_mod(2,n>>1);
  }
  cout<<"\n";
  return 0;
}