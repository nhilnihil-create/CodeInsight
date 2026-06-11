#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 1000005

ll dp[MAX_N] = {};
int dpnext[MAX_N];
char nextchar[MAX_N];
int next_[MAX_N][26];
int zflag[MAX_N];
int zz = 0;
string s;
ll n;
string ans;

void dfs(int x){
    if(dp[x] != 0) return;
    dp[x] = 1001001001;    
    rep(j,26){
        int y = next_[x][j];
        if(y == n){
            dp[x] = 1;
            dpnext[x] = n;
            nextchar[x] = (char)(j + 'a');
            break;
        }else{
            dfs(y);
            if(dp[y]+1 < dp[x]){
                dp[x] = dp[y] + 1;
                dpnext[x] = y;
                nextchar[x] = (char)(j + 'a');
            }
        }
    }
    return;
}

void calc(int x){
    if(x == n)return;
    ans += nextchar[x];
    calc(dpnext[x]);
}

int main() {
    cin >> s;
    s = '*' + s; // 1文字目にダミー文字挿入.
    n = s.size();

    // 各アルファベットに対して次の位置を記憶する.
    drep(i,n){
        rep(j,26){
            if(i == n-1) next_[i][j] = n;
            else next_[i][j] = next_[i+1][j];
        }
        if(i < n-1){
            next_[i][s[i+1]-'a'] = i+1;
        }
    }

    dfs(0);

    calc(0);

    cout << ans << endl;
    return 0;
}


