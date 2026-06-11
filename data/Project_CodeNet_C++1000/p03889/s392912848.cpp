#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string S; cin >> S;
    bool ans = true;
    for (int i = 0; i < S.size(); i++) {
        int irev = S.size() - 1 - i;
        ans &= (S[i] == 'b' && S[irev] == 'd')
            || (S[i] == 'd' && S[irev] == 'b')
            || (S[i] == 'p' && S[irev] == 'q')
            || (S[i] == 'q' && S[irev] == 'p');
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
