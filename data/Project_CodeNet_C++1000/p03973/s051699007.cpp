#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define PN() {cout << "No" << endl; return 0;}
#define PY() {cout << "Yes" << endl; return 0;}

int main(){
  int n; cin >> n;
  vector<long long int> a(n); for(int i=0;i<n;i++) cin >> a[i];
  int m = 1;
  long long int ans=0;
  ans += a[0] - 1;
  for(int i=1;i<n;i++){
    if(a[i] == (m+1)){
      m = a[i];
    }
  	else if(a[i] % (m+1) == 0){
      long long int t = (a[i] / (m+1)) - 1;
      ans = ans + t;
    }
    else {
      ans = ans + ( a[i] / (m+1) );
      a[i] = a[i] % (m+1);
    }
  }
 // for(int i=0;i<n;i++) cout << i+1 << ":" << a[i] << endl;
  cout << ans << endl;
  return 0;
}
