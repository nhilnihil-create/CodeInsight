#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int AL = 26;

int nxt[AL];

int dp[N];
int let[N];
int pos[N];

int main(){
    fastIO;
    string t;
    cin >> t;
    int n = t.size();
    for(int i = 0 ; i < AL; i ++ )
        nxt[i] = n+1;
    for(int i = 0 ; i < N; i ++ ){
        dp[i] = n + 12412;
        let[i] = -1;
        pos[i] = i;
    }
    int f;
    dp[n]=1;
    dp[n+1]=0;
    for(int i = n - 1; i >= 0 ; i -- ){
        f = t[i] - 'a';
        nxt[f] = i + 1;
        for(int j = 0 ; j < AL; j ++ ){
            if(dp[nxt[j]] + 1 < dp[i]){
                dp[i] = dp[nxt[j]] + 1;
                pos[i] = nxt[j];
                let[i] = j;
            }
        }
    }
    int p = 0;
    while(p < n){
        cout << char('a'+let[p]);
        p = pos[p];
    }
    return 0;
}