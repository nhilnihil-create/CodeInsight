#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;


string s;
int ans;

int main(void) {
    cin >> s;
    int r = 0, p = 0;
    for(int i=0; i<(int)s.size(); i++) {
      if (p<r) {
        if (s[i]=='g')  ans++;
        p++;
      } else {
        if (s[i]=='p') ans--;
        r++;
      }
    }
    cout << ans << endl;

	return 0;
}
