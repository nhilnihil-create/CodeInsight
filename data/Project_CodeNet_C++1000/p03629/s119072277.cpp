#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-11;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()


int main() {
    int n, dp[MAX_N][2]{};
    vector<int> ls[26];
    string s, ans="";
    cin >> s;
    n = s.size();
    REP(i,n){
        ls[s[i]-'a'].push_back(i+1);
    }
    REP(i,26) ls[i].push_back(n+1);
    REPR(i,n+2)fill(dp[i],dp[i]+2,IINF);
    dp[n+1][0] = 0;
    REPR(i,n){
        REP(j,26){
            int k = *upper_bound(ALL(ls[j]),i);
            if(dp[i][0] > (dp[k][0]/100+1)*100+j){
                dp[i][0] = (dp[k][0]/100+1)*100+j;
                dp[i][1] = k;
            }
        }
    }
    for(int i=0;i<=n;i=dp[i][1]){
        ans.push_back('a'+dp[i][0]%100);
    }
    cout << ans << endl;
    return 0;
}
