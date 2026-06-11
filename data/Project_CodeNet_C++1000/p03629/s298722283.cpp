#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin >> str;

    vector<string> dp(26);
    for(int i = 0; i < 26; i++){
        dp[i] = (char)('a' + i);
    }

    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 26; j++){
            if((char)('a'+j) == str[i]){
                string tmp = dp[j];
                for(int k = 0; k < 26; k++){
                    if(k == j){
                        dp[j] += (char)('a' + j);
                        continue;
                    }
                    if(dp[k].size() > tmp.size()+1 || (dp[k].size() == tmp.size()+1 && dp[k] > tmp+(char)('a'+k))){
                        dp[k] = tmp + (char)('a' + k);
                    }
                }
            }
        }
    }

    string ans = dp[0];
    for(int i = 1; i < 26; i++){
        if(dp[i].size() < ans.size() || (dp[i].size() == ans.size() && dp[i] < ans)){
            ans = dp[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}