#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;

int main() {
  ll n,x;
  cin >> n >> x;
  vector<ll>a(n),b(n-1);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n-1; i++) b[i]=a[i]+a[i+1];
  ll count=0;
  for(int i=0; i<n-1; i++){
    ll res = b[i]-x;
    if(b[i]<=x) continue;
    if(a[i+1]>=res) b[i]-=res,b[i+1]-=res,count+=res;
    else b[i]-=a[i+1],b[i+1]-=a[i+1],count+=a[i+1];
  }
  if(b[0]>x)count+=b[0]-x;
  if(b[n-2]>x && 0!=n-2)count+=b[n-2]-x;
  cout << count << endl;
  return 0;
}