#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int gcd(int a, int b)
{
  if(a%b == 0) return b;
  else return gcd(b, a%b);
}

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  int i;
  int vmax = 0;
  rep(i,n)
  {
    cin >> a[i];
    if(a[i] > vmax) vmax = a[i];
  }
  int mgcd = a[0];
  rep(i,n-1)
  {
    mgcd=gcd(mgcd, a[i+1]);
  }
  bool ok = true;
  if(k > vmax) ok = false;
  else if(k%mgcd != 0) ok = false;
  if(ok) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
