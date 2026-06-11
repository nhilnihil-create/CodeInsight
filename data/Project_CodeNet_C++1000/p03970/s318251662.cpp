#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    string S; cin >> S;
    string aim = "CODEFESTIVAL2016";
    int ans = 0;
    rep(i, 16) if(S[i] != aim[i]) ans++;
    cout << ans << endl;
    return 0;
}