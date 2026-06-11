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
const int INF = 1001001001; // > 10^9
const int MOD = (int)1e9 + 7;
const ll INFLL = 1001001001001001001;  // > 10^18
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int n,k; cin >>n>>k;
    vector<int> a(n); rep(i,n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int ng = n;
    int ok = -1;
    while (abs(ok-ng)>1) {
        int i = (ok+ng)/2;
        int mem = a[i];
        a.erase(a.begin()+i);
        vector<vector<bool> > dp(n, vector<bool>(k, false));
        dp[0][0] = true;
        for (int j = 0; j < n-1; j++) {
            for (int l = 0; l < k; l++) {
                dp[j+1][l] = (dp[j+1][l] || dp[j][l]);
                if (l - a[j] >= 0) {
                    dp[j+1][l] = (dp[j+1][l] || dp[j][l - a[j]]);
                } 
            }
        }
        bool ans = false;
        for (int l = 0; l < k; l++) {
            if (k - mem <= l) {
                ans = (ans || dp[n-1][l]);
            } 
        }
        if (ans) {
            ok = i;
        } else {
            ng = i;
        } 
        a.insert(a.begin()+i, mem);
    }

    cout << n - (ok+1) << endl;
    
    return 0;
}


