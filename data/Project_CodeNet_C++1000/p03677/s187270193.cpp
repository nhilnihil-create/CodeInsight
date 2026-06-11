#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

signed main(){

    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i != 0){
            cnt[a[i]] += ((a[i] - a[i - 1] + m) % m - 1);
        }
    }

    /*for(int i = 0; i <= m; i++){
        cout << cnt[i] << " ";
    }
    cout << endl;*/

    vector<int> imos(m + 2, 0);
    //x は [1, m] を動く
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] > a[i]){
            imos[a[i] + 1]++;
            imos[a[i + 1]]--;
        }else{
            //二か所をいじる感じ
            imos[a[i] + 1]++;
            imos[m + 1]--;

            imos[1]++;
            imos[a[i + 1]]--;
        }
    }

    for(int i = 2; i <= m + 1; i++){
        imos[i] += imos[i - 1];
    }

    //dp[i] := i = x の時のボタンを押す必要のある回数
    vector<int> dp(m + 1, 0);
    int x = 1;
    for(int i = 0; i < n - 1; i++){
        dp[1] += min((a[i + 1] - a[i] + m) % m, 1 + (a[i + 1] - x + m) % m); 
    }

    int ans = dp[1];
    for(int x = 1; x < m; x++){
        int add = 0;
        add -= imos[x];
        add += cnt[x];
        dp[x + 1] = dp[x] + add;
        ans = min(ans, dp[x + 1]);
    }

    cout << ans << endl;
    return 0;
}