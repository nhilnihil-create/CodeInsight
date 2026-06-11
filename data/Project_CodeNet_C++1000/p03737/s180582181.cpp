#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    transform(all(s1), s1.begin(), ::toupper);
    transform(all(s2), s2.begin(), ::toupper);
    transform(all(s3), s3.begin(), ::toupper);
    cout << s1[0];
    cout << s2[0];
    cout << s3[0] << endl;
}
