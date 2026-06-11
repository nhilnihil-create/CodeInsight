#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string A, B;
    cin >> A >> B;

    if (A.size() < B.size()) A.insert(A.begin(), '0');
    if (A.size() > B.size()) B.insert(B.begin(), '0');

    if (A > B) cout << "GREATER" << endl;
    if (A < B) cout << "LESS" << endl;
    if (A == B) cout << "EQUAL" << endl;

    return 0;
}