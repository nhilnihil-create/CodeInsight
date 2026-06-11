#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  vector<ll> a(3*n);
  rep(i,3*n) cin >> a[i];
  sort(a);
  reverse(a);
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += a[2*i+1];
  }
  cout << ans << endl;
}