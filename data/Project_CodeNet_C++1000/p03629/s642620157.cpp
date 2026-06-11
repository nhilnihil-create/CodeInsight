#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<char,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;

vector<vector<int>> nextIndex(const string &s){
    int n = s.length();
    vector<vector<int>> ret(n+1,vector<int> (26,n));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) ret[i][j] = ret[i+1][j];
        ret[i][s[i]-'a'] = i;
    }
    return ret;
}


int main(){
    string s;cin >> s;
    int n = s.length();
    auto p = nextIndex(s);
    vector<int> dp(n+2,INF);
    vector<P> res(n+2,make_pair(',',n));
    dp[n+1] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            int ni;
            if(i>=n) ni = n;else ni = p[i][j];
            if(dp[i] > dp[ni+1]+1){
                dp[i] = dp[ni+1]+1;
                res[i] = make_pair('a'+j,ni+1);
            }
        }
    }
    int indx = 0;
    string ans = "";
    for (int k = 0; k < dp[0]; k++) {
        ans += res[indx].fs;
        indx = res[indx].sc;
    }
    cout << ans << endl;
    return 0;
}

