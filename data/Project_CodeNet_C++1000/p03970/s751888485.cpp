#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    string T = "CODEFESTIVAL2016";

    ll ans = 0;
    Rep (i, 16) {
        if (S[i] != T[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
}