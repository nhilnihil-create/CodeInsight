#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  if(sum%(n*(n+1)/2)!=0) {
    cout << "NO" << endl;
    return 0;
  }
  ll k = sum/(n*(n+1)/2);
  vector<ll> b(n);
  rep(i,n) b[i]=a[(i+1)%n]-a[i%n];
  ll c=0;
  rep(i,n) {
    b[i]-=k;
    if(b[i]>0||(-b[i])%n!=0) {
      cout << "NO" << endl;
      return 0;
    }
    c+=-b[i]/n;
  }
  if(c==k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
