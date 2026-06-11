#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string s1(1e5, ' ');
    int    n = 0;
    for (int i = 0, e = s.size(); i < e; i += 2) {
        s1[n] = s[i];
        ++n;
    }
    cout << s1.substr(0, n) << endl;
}
