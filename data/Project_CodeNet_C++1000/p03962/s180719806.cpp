/*
      author : nishi5451
      created: 10.08.2020 23:54:31
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<int> dp(101);
    int a;
    rep(i,3){
        cin >> a;
        dp[a]++;
    }
    int ans = 0;
    for(int i=1; i<=100; i++){
        if(dp[i]!=0) ans++;
    }
    cout << ans << endl;
    return 0;
}