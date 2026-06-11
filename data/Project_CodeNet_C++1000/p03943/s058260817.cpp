#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> line = {a, b, c};

    sort(line.begin(), line.end());

    if (line.at(2) == line.at(0) + line.at(1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}