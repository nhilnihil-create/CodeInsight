#include "bits/stdc++.h"
using namespace std;
#define dbg(var) cout<<#var<<"="<<var<<" "
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
//#define int long long
template<typename T>
vector<int> get_pi(const T &a) {
  int n = a.size();
  vector<int> pi(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && a[i] != a[j]) j = pi[j - 1];
    j += ((a[i] == a[j]) ? 1 : 0);
    pi[i] = j;
  }
  return pi;
}

int32_t main()
{
	int n; cin >> n;
	string s,t; cin >> s >> t;
	t = t + "#" + s;
    auto pi = get_pi(t);
    cout << 2*n - pi.back();
    		
}