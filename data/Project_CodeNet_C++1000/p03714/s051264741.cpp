#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

const ll INF = 1LL << 60;

int main(){
  int n; cin >> n;
  vector<ll> a(3*n);
  rep(i,3*n) cin >> a[i];

  priority_queue<ll,vector<ll>,greater<ll>> q;
  vector<ll> left(n+1);
  ll sum = 0;
  rep(i,n){
    sum += a[i];
    q.push(a[i]);
  }
  left[0] = sum;
  for(int i = n; i < 2*n; i++){
    sum += a[i];
    q.push(a[i]);
    sum -= q.top(); q.pop();
    left[i-n+1] = sum;
  }


  priority_queue<ll> q2;
  vector<ll> right(n+1);
  ll sum2 = 0;
  for(int i = n*3-1; i >= n*2; i--){
    sum2 += a[i];
    q2.push(a[i]);
  }
  right[n] = sum2;
  for(int i = n*2-1; i >= n; i--){
    sum2 += a[i];
    q2.push(a[i]);
    sum2 -= q2.top(); q2.pop();
    right[i-n] = sum2;
  }
  ll ans = INF * -1;
  rep(i,n+1) chmax(ans, left[i]-right[i]);
  cout << ans << endl;

  return 0;
}
