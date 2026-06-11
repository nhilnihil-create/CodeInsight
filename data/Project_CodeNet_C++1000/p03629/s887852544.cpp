#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
bool used[26];
int cnt = 0;
void clear(){
    cnt = 0;
    for(int i = 0; i < 26; i++) used[i] = false;
}

vector<int> v[26];
int dp[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string A;
    cin >> A;
    int cur = 1;
    dp[A.size()] = 0;
    for(int i = A.size()-1; i >= 0; i--){
        dp[i] = cur;
        if(!used[A[i]-'a']){
            cnt++;
            used[A[i]-'a'] = true;
        }
        if(cnt == 26){
            cur++;
            clear();
        }
    }
    for(int i = 0; i < A.size(); i++){
        v[A[i]-'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++){
        v[i].push_back(A.size());
    }
    string ans;
    // cout << cur << endl;
    // for(int i = 0; i <= A.size(); i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    int idx = -1;
    while(cur > 0){
        for(int i = 0; i < 26; i++){
            char c = 'a'+i;
            auto p = upper_bound(v[i].begin(), v[i].end(), idx);
            if(dp[*p] < cur){
                // cout << *p << ' ' << cur << endl;
                ans += c;
                idx = *p;
                cur--;
                break;
            }
        }
    }
    cout << ans << endl;
}