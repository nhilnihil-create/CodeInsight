#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define BUFF ios::sync_with_stdio(false);

typedef long long int ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9+7;
const ld pi = acos(-1);

int main() { BUFF
  string s; cin >> s;
  for(int i=0; i<s.size()-1; i++) {
    if(s[i] == s[i+1]) {
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
    if(s[i] == s[i+2]) {
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}
