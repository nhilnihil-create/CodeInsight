#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

string divide[4] = {"dream", "dreamer", "erase", "eraser"};
bool dp[100010];

int main(){
    string S;
    cin >> S;

    dp[0] = 1;
    for(int i = 0; i < S.size(); ++i) {
        if(dp[i] == 0) continue;
        for(string s : divide) {
            if(S.substr(i, s.size()) == s) {
                dp[i + s.size()] = 1;
            }
        }
    }

    cout << (dp[S.size()] ? "YES" : "NO") << endl;
    return 0;

    return 0;
}