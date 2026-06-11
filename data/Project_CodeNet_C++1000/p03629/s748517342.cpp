#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200100;
int dp[maxn], n;
int last_ind[30];
string code;
int pntr[maxn];
char c[maxn];

int main() {
    cin>>code;
    n = code.length();

    for(int i=0;i<26;i++) last_ind[i] = n;

    pntr[n] = n + 1;
    c[n] = 'a';
    dp[n] = 1;
    dp[n+1] = 0;
    code += 'a';
    for(int i=n-1;i>=0;i--) {
        // fix character i as start of the subsequence
        // let j -> be the second character of the result

        last_ind[int(code[i] - 'a')] = i;

        dp[i] = 1000000;
        for(int j=0;j<26;j++) {

            if(dp[last_ind[j] + 1] + 1 < dp[i]) {
                dp[i] = dp[last_ind[j] + 1] + 1;
                pntr[i] = last_ind[j] + 1;
                c[i] = char('a' + j);
            }
        }
    }

    int result = dp[0];
    int x = 0;
    while(result) {
        cout<<c[x];
        x = pntr[x];
        result--;
    }

    return 0;
}