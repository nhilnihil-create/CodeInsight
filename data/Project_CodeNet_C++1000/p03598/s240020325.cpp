#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector <int> x(n);
    vector <int> dp(n);
    long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        dp[i] = min(abs(x[i]),abs(x[i]-k));
        ans+=2*dp[i];
    }
    cout << ans << endl;
    return 0;
}