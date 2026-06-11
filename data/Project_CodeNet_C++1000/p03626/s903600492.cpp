#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000007;
string s1, s2;

int dp[53][4][4], n;

void adds(int &a, int b) {
    a = (a + b) % mod;
}

int sol(int t, int p1, int p2) {
    if(t == n)
        return 1;
    if(dp[t][p1][p2] != -1)
        return dp[t][p1][p2];
    int sum = 0;
    if(s1[t] == s2[t]) {
        for(int i = 0; i < 3; ++i)
            if(p1 != i && p2 != i)
                adds(sum, sol(t + 1, i, i));
    } else {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                if(p1 != j && p2 != i && i != j)
                    adds(sum, sol(t + 2, j, i));
    }
    return dp[t][p1][p2] = sum % mod;
}


int main() {
    cin >> n >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << sol(0, 3, 3) << endl;
    return 0;
}