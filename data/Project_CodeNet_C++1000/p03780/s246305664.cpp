#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;

void DODP(vector<vector<bool>> &dp, const vector<int> &a) {
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(!dp[i][j])continue;
            dp[i + 1][j] = true;
            dp[i + 1][min(k, j + a[i])] = true;
        }
    }
}


//サイズは全部k + 1
bool marge(vector<bool> dp1, vector<bool> dp2, int a) {
    if(a >= k)return false;
    // for(int i = k - 1; i >= k - a; i--)if(dp1[i] || dp2[i])return false;
    vector<int> fr, bc;
    for(int i = 0; i < k; i++) {
        if(dp1[i])fr.push_back(i);
        if(dp2[i])bc.push_back(i);
    }
    int m = fr.size();
    for(int i = 0; i < m; i++) {
        auto les = lower_bound(bc.begin(), bc.end(), k - a - fr[i]);
        auto gre = lower_bound(bc.begin(), bc.end(), k - fr[i]);
        if(les != gre)return false;
    }
    return true;
}


int main()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    vector<vector<bool>> dpf(n + 1, vector<bool>(k + 1)), dpb(n + 1, vector<bool>(k + 1));
    DODP(dpf, a);
    reverse(a.begin(), a.end());
    DODP(dpb, a);
    reverse(a.begin(), a.end());

    int cnt = 0;
    // print(dpb[n - 1]);
    for(int I = 0; I < n; I++) {
        bool res = marge(dpf[I], dpb[n - I - 1], a[I]);
        if(res)cnt++;
    }
    cout << cnt << endl;
}

