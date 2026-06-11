#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int num = 0;
    int ans = 0;
    for (char c : s) {
        if (c == 'I') num++;
        else num--;
        ans = max(ans, num);
    }
    cout << ans << endl;
}
