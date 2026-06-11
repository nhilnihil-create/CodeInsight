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
    vector<int> dp(n+1,INF);
    vector<P> res(n+1,make_pair(',',n));
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if(p[i][j]==n){
                if(dp[i]>1){
                    dp[i] = 1;
                    res[i] = make_pair('a'+j,n);
                }
            }
            else if(dp[i] > dp[p[i][j]+1]+1){
                dp[i] = dp[p[i][j]+1]+1;
                res[i] = make_pair('a'+j,p[i][j]+1);
            }
        }
    }
    int indx = 0;
    string ans = "";
    while(indx < n){
        ans += res[indx].fs;
        indx = res[indx].sc;
    }
    cout << ans << endl;
    return 0;
}

