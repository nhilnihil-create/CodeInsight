

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, sum;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I')
            ++sum;
        else
            --sum;
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}

