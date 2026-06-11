#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << x << endl;
#define END cout << endl;
#define sorti(x) sort(x.begin(), x.end())

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
  }
  ll res = 0;
  rep(i,n) {
    if (a[i] == i+1)   {
      res++;
      swap(a[i], a[i+1]);
    }
  }

  cout << res << endl;
}