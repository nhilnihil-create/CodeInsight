#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

vector<vector<int>> DP(500, vector<int>(500, 1e8));

int main()
{
    int n, MA, MB;
    cin >> n >> MA >> MB;
    DP[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vector<vector<int>> dp = DP;

        for(int i = 0; i < 400; i++){
            for(int j = 0; j < 400; j++){
                DP[i + a][j + b] = min(dp[i + a][j + b],dp[i][j] + c);
            }
        }
    }
    int ans = 10000000;
    for(int cef = 1; cef < 500; cef++){
        if(MA * cef > 450 || MB * cef > 450)continue;
        ans = min(DP[cef * MA][cef * MB], ans);
    }
    cout << (ans == 10000000 ? -1 : ans) << endl;

}
