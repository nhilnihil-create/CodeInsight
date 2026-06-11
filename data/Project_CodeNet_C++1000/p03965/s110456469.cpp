#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const ll INFLL = 1001001001001001001;  // > 10^18
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    string s; cin >>s;
    int n = s.length();

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            c = c + 1;
        }
    }

    int ans = n/2 - c;
    cout << ans << endl;
    
    return 0;
}
