#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  int i;
  rep(i,m) cin >> a[i] >> b[i];
  vector<int> count(n+1,0);
  rep(i,m)
  {
    count[a[i]]++;
    count[b[i]]++;
  }
  bool ok = true;
  rep(i,n+1)
  {
    if(count[i]%2 != 0) ok = false;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}