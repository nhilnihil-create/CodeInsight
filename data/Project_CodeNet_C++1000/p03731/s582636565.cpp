#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n,t;
  cin >> n >> t;
  vector<int> s(n);
  rep(i,n) cin >> s[i];
  vector<ll> a(n);
  a[0] = s[0] + t;
  for(int i=1;i<=n-1;i++){
    a[i] = a[i-1] + t - max(s[i-1]+t-s[i],0);
  }
  cout << a[n-1] << endl;
}