#include<bits/stdc++.h>
using namespace std;

int n, k;

bool check(int mid, vector<int> &a){
    vector<bool> dp(k, false);
    dp[0] = true;
    for (int i = 0; i < n; i++){
        if (a[i] > k) break;
        if (i == mid) continue;
        vector<bool> dp2 = dp;
        for (int j = 0; j < k; j++){
            if (dp[j] && j + a[i] < k) dp2[j + a[i]] = true;
        }
        dp = dp2;
    }
    bool flag = false;
    for (int i = k - a[mid]; i < k; i++) if (dp[i]) flag = true;
    return flag;
}

int main(){
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int border = n;
    for (int i = 0; i < n; i++){
        if (a[i] >= k){
            border = i;
            break;
        }
    }
    int ok = border;
    int ng = - 1;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if (check(mid, a)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}