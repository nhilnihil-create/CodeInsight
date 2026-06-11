#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr Int MOD = 1e9 + 7;
int main()
{
    string S; cin >> S;
    cout << S.substr(0, 4) + ' ' + S.substr(4) << endl;
    return 0;
}
