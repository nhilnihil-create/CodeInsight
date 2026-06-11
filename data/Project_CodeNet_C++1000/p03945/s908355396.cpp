#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n=s.size();
    vector<int>dp(n,0);
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i+1]=dp[i];
        }
        else {
            dp[i+1]=dp[i]+1;
        }
    }
    cout << dp[n-1] << endl;
}