#include <bits/stdc++.h>
using namespace std;

constexpr int IINF = INT_MAX;

int main() {
    int n;
    string a;
    cin >> a;
    n = a.size();
    vector<int> dp(n+2, IINF);  // i文字目までの部分文字列でない最小文字数
    vector<vector<int> > pos(26);
    vector<vector<pair<pair<char,char>,int> > > pre(n+2);

    for(int i=0;i<26;i++) pos[i].push_back(0);
    for(int i=0;i<n;i++){
        pos[a[i]-'a'].push_back(i+1);
    }

    dp[n+1] = 0;
    a.push_back('#');
    for(int i=n+1; i>0; i--){
        for(int j=0; j<26; j++){
            int k = *--lower_bound(pos[j].begin(), pos[j].end(), i);
            if(dp[k] > dp[i]+1){
                dp[k] = dp[i]+1;
                pre[k].clear();
                pre[k].push_back({{'a'+j,a[i-1]},i});
            }
            else if(dp[k] == dp[i]+1){
                pre[k].push_back({{'a'+j,a[i-1]},i});
            }
        }
    }
    // 復元
    string ans = "";
    for(int i=0;i<n;){
        sort(pre[i].begin(),pre[i].end());
        ans.push_back(pre[i][0].first.first);
        i = abs(pre[i][0].second);
    }
    cout << ans << endl;
    return 0;
}
