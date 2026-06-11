//解説あり
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans = 500;

int main(void) {
  string s;
  cin >> s;
  int n = (int)s.size();
  
  for (char c = 'a'; c<='z'; c++) {
    string t = s;
    int _n = n;
    while (_n>=1) {
      bool ok = true;
      for (int i=0; i<_n-1;i++){
        if (t[i]!=t[i+1]) ok = false;
      }
      if(ok) break;
      
      for (int i=0; i<_n-1;i++){
        if (t[i+1]==c) t[i] = t[i+1];
      }
      _n--;
 
    }
    ans = min(ans, n-_n);
  
  }
  cout << ans << endl;
	return 0;
}
