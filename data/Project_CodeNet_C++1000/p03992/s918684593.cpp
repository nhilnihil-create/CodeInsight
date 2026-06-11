#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
    cin >> S;

    cout << S.substr(0, 4) << " " << S.substr(4, S.length() - 4) << endl;

    return 0;
}
