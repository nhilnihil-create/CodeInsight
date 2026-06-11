#include <bits/stdc++.h>

#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, l;
    cin >> n >> l;

    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end());
    for (string ss : s) {
        cout << ss;
    }
    return 0;
}
