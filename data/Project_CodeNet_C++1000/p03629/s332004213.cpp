#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = ";" + s;
    vector <int> dp(n + 2);
    vector <int> cur_las(26, n + 1);
    vector <vector <int> > las(n + 1);
    for(int i = n ; i >= 0 ; i--){
        las[i] = cur_las;
        dp[i] = 1e9;
        for(int j = 0 ; j < 26 ; j++){
            dp[i] = min(dp[i], dp[cur_las[j]] + 1);
        }
        if(i > 0){
            cur_las[s[i] - 'a'] = i;
        }
    }
    string ans;
    int len = dp[0];
    int cur = 0;
    while(cur <= n){
        for(int i = 0 ; i < 26 ; i++){
            if(dp[las[cur][i]] == len - 1){
                ans += i + 'a';
                cur = las[cur][i];
                len--;
                break;
            }
        }
    }
    cout << ans << endl;
}
