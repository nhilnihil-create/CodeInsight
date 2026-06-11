#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<char,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

vector<vector<int>> nx(const string &s){
    int n = s.length();
    vector<vector<int>> ret(n+1,vector<int> (26,n));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            ret[i][j] = ret[i+1][j];
        }    
        ret[i][s[i]-'a'] = i;
    }
    return ret;
}

int main(){
    string s;cin >> s;
    int n = s.length();
    auto p = nx(s);
    vector<int> dp(n+2,INF);
    vector<P> res(n+2,mp(',',0));
    for (int i = 0; i <= 26; i++) {
        res[n+1] = mp('a',1);
    }
    dp[n+1] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            int t = n;
            if(i!=n) t = p[i][j];
            if(dp[i] > dp[t+1] + 1){
                dp[i] = dp[t+1] + 1;
                res[i] = mp('a'+j,t+1); 
            }
        }
    }
    int idx = 0;
    while(idx<n){
        cout << res[idx].fs;
        idx = res[idx].sc;
    }
    cout << "\n";
    return 0;
}
