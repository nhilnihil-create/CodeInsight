#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string S; cin >> S;
    const string A = "CODEFESTIVAL2016";
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != A[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}
