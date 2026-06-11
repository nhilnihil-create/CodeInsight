#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[200002][26];
int d[200002];

int main()
{
    string a;
    cin >> a;
    int n = a.size();
    for(int j = 0; j < 26; j++) dp[n][j] = n;
    int l[26] {0};
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++) dp[i][j] = dp[i + 1][j];
        int r = 10000000;
        for(int j = 0; j < 26; j++) r = min(r, l[j]);
        l[a[i] - 'a'] = r + 1;
        d[i] = r + 1;
        dp[i][a[i] - 'a'] = i;
    }
    int now = 0;
    while(true){
        int r = 10000000;
        int ar = -1;
        for(int j = 25; j >= 0; j--){
            if(d[dp[now][j]] <= r){
                r = d[dp[now][j]];
                ar = j;
            }
        }
        cout << char('a' + ar);
        if(r == 0) break;
        now = dp[now][ar] + 1;
    }
}