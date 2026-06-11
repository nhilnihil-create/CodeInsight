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
    int start = 0;
    int end   = 0;
    for (int i = 0, e = s.size(); i < e; ++i) {
        if (s[i] == 'A') {
            start = i;
            break;
        }
    }
    for (int i = s.size() - 1, e = 0; i >= e; --i) {
        if (s[i] == 'Z') {
            end = i;
            break;
        }
    }
    cout << end - start + 1 << endl;
}
