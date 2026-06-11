#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << char(s1[0] - 32) << char(s2[0] - 32) << char(s3[0] - 32) << endl;
}