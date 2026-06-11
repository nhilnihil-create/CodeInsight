#include <bits/stdc++.h>
using namespace std;
 
using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

string A;
int nxt[300000][26];

int dp[300000];
const int INF = 1 << 29;

int rec(int pos) {
    if(dp[pos] >= 0)  return dp[pos];
    int res = INF;
    for(int i = 0; i < 26; i++){
        int n = nxt[pos][i];
        if(n != -1){
            res = min(res, rec(n) + 1);
        }
        else{
            res = 0;
        }
    }
    return dp[pos] = res;
}

int main(){

    cin >> A;
    
    int last[30];
    memset(last, -1, sizeof(last));

    for(int i = (int)A.size() - 1; i >= 0; i--){
        int c = A[i] - 'a';
        for(int j = 0; j < 26; j++){
            nxt[i+1][j] = last[j];
        }
        last[c] = i + 1;
    }

    for(int j = 0; j < 26; j++){
        nxt[0][j] = last[j];
    }

    memset(dp, -1, sizeof(dp));
    
    string ans;
    int pos = 0;
    bool is_end = false;
    while(!is_end){
        for(int i = 0; i < 26; i++){
            int n = nxt[pos][i];
            if(n == -1){
                is_end = true;
                ans += ('a' + i);
                break;
            }
        }
        if(is_end) break;

        for(int i = 0; i < 26; i++){
            int n = nxt[pos][i];
            if(rec(pos) == rec(n) + 1){
                pos = n;
                ans += A[pos - 1];
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}
