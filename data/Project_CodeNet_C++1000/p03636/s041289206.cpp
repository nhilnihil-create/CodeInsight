#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    string s; cin >> s;

    int num = s.size() - 2;
    cout << s[0] << num << s.back() << endl;

}
