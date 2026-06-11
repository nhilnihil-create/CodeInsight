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
  int n,m;
  cin>>n>>m;
  vector<ll> x(n);
  vector<ll> y(m);
  rep(i,n)cin>>x[i];
  rep(i,m)cin>>y[i];
  ll a=0;
  ll b=0;
  const ll p = 1e9+7;
  rep(i,n) {
    a+=(2*(i+1)-n-1)*x[i];
    a%=p;
  }
  rep(i,m) {
    b+=(2*(i+1)-m-1)*y[i];
    b%=p;
  }
  cout << (a*b)%p << endl;
  return 0;
}
