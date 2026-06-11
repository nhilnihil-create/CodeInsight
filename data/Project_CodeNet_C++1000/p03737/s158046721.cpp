#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int diff = 'A' - 'a';

    cout << (char)(s1.at(0) + diff) << (char)(s2.at(0) + diff) << (char)(s3.at(0) + diff) << endl;
    return 0;
}