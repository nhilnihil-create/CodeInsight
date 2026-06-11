#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    vector<long long> dp(n, 0);
    long long max_sell = A[n-1];
    long long max_value = 0;
    for(int i = n-2; i >= 0; i--){
        //cout << n-2 << endl
        dp[i] = max(dp[i], max_sell - A[i]);
        max_sell = max(max_sell, A[i]);
        max_value = max(max_value, dp[i]);
    }

    /*for(int i = 0; i < n; i++){
        cout << i << " " << dp[i] << endl;
    }*/

    int cost = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == max_value) cost++;
    }

    cout << cost << endl;

    return 0;
}