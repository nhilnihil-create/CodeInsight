/**
 * Title: C - 高橋君とカード / Tak and Cards
 * Url: https://atcoder.jp/contests/abc044/tasks/arc060_a
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>

using namespace std;

#define ll long long

const int MAX_N = 51;
const int MAX_A = 10000;

int n, a;

ll dp[MAX_N][MAX_N][MAX_A];

ll rec(int i, int s, int num, vector<int> x) {
    if(dp[i][num][s]!=-1) return dp[i][num][s];
    if(i>=n) {
        if(num==0) return 0;
        if(s/(double)num==(double)a) return 1;
        return 0;
    }
    ll ans = rec(i+1, s+x[i], num+1, x) + rec(i+1, s, num, x);
    dp[i][num][s] = ans;
    return ans;
}

int main() {
    cin >> n >> a;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<MAX_N; i++) {
        for(int j=0; j<MAX_N; j++) {
            for(int k=0; k<MAX_A; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << rec(0, 0, 0, x) << endl;
    return 0;
}