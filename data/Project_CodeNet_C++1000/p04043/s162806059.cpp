#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    
    string word = A + B + C;

    if (word == "575") {
        cout << "YES" << endl;
    } else if (word == "557") {
        cout << "YES" << endl;
    } else if (word == "755") {
        cout << "YES" << endl;
    } else
    {
        cout << "NO" << endl;
    }

    return 0;
}