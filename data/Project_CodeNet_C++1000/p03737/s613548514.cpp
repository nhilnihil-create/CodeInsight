#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    string ans = "aaa";
    ans.at(0) = s1.at(0) + ('A' - 'a');
    ans.at(1) = s2.at(0) + ('A' - 'a');
    ans.at(2) = s3.at(0) + ('A' - 'a');

    cout << ans << endl;
}