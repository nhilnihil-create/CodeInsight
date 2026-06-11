#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> a(27);
    for (auto i : s) {
        a[i - 96]++;
    }
    for (auto i : a) {
        if (i % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
