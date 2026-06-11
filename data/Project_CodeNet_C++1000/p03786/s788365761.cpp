#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  int pos = 0;
  ll sum = 0;
  rep(i, n - 1) {
    sum += a[i];
    if (sum * 2 < a[i + 1]) pos = i + 1;
  }
  cout << n - pos << endl;
}