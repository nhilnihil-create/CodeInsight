#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 1e9+1;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> odd;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 != 0) odd.insert(a[i]); 
  }
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && odd.count(a[i])) res++; 
  }
  cout << res << endl;
  return 0;
} 