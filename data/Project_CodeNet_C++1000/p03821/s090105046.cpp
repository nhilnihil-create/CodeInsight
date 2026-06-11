#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
     
signed main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n; cin >> n;
  vector <int> a(n), b(n);
  
  for(int i = 0; i < n; i++) {
  	cin >> a[i] >> b[i];
  }

  int check = 0;

  for(int i = n - 1; i >= 0; i--) {
    a[i] += check;
    if(a[i] % b[i] == 0) continue;
    check += b[i] - (a[i] % b[i]);
  }
  
  cout << check << endl;
  
  return 0;
}