#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long n, ans=-1e15;
  cin >> n;
  vector<ll> a(3*n);
  for(int i=0;i<3*n;i++){
    cin >> a[i];
  }
  priority_queue<int, vector<int>, greater<int> > quemi;
  priority_queue<int> quema;
  vector<ll> zenhan(n+1, 0ll), kouhan(n+1, 0ll);
  for(int i=0;i<n;i++){
    zenhan[0]+=a[i];
    quemi.push(a[i]);
  }
  for(int i=2*n;i<3*n;i++){
    kouhan[n]+=a[i];
    quema.push(a[i]);
  }
  for(int i=n;i<2*n;i++){
    quemi.push(a[i]);
    zenhan[i-n+1] = zenhan[i-n]+a[i]-quemi.top();
    quemi.pop();
  }
  for(int i=2*n-1;i>=n;i--){
    quema.push(a[i]);
    kouhan[i-n] = kouhan[i-n+1]+a[i]-quema.top();
    quema.pop();
  }
  for(int i=0;i<n+1;i++){
    ans = max(ans, zenhan[i]-kouhan[i]);
  }
  cout << ans << endl;
  return 0;
}
