#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    string T = "CODEFESTIVAL2016";
    cin >> S;
    int ans = 0;
    rep(i,S.size()){
        if(S[i]!=T[i])ans++;
    }
    cout << ans << endl;
}