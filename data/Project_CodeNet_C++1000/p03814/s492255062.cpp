
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int r = s.length() - 1;
    int l = 0;
    while (s[l] != 'A')
        ++l;
    while (s[r] != 'Z')
        --r;
    cout << r - l + 1 << endl;

    return 0;
}

