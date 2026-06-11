#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int dp[MAX_N];
vector<int> cnt[26];
string A, ans;

int main(){
    cin >> A;

    for(int i=0;i<A.size();i++) cnt[A[i]-'a'].push_back(i+1);
    for(int i=0;i<26;i++) cnt[i].push_back(A.size()+1);

    for(int i=0;i<=A.size();i++) dp[i] = 100005;
    for(int i=A.size();0<=i;i--){
        for(int j=0;j<26;j++){
            int next = *upper_bound(cnt[j].begin(), cnt[j].end(), i);
            dp[i] = min(dp[i], dp[next]+1);
        }
    }

    int cur = 0;
    while(dp[cur]){
        for(int j=0;j<26;j++){
            int next = *upper_bound(cnt[j].begin(), cnt[j].end(), cur);
            if(dp[cur] == dp[next]+1){
                ans += (char)('a'+j); cur = next;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}