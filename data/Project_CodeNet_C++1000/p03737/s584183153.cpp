#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1[0] = toupper(s1[0]);
    s2[0] = toupper(s2[0]);
    s3[0] = toupper(s3[0]);
    cout << s1[0] << s2[0] << s3[0] << endl;
    return 0;
}