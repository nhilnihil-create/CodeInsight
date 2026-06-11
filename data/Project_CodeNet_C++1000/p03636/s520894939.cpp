#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    string s;
    cin >> s;
    cout << s[0] + to_string(s.size() - 2) + s[s.size() - 1] << endl;

}