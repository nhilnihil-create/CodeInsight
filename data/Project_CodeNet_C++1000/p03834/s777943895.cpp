#include <bits/stdc++.h>
#define MAXN 200100
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const ll mod = 1e9 + 7;
ll memo[MAXN];



int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    for (int i=0; i< (int)s.size(); i++){
        if (s[i] == ',') cout << " ";
        else cout << s[i];
    }
    cout << endl;
    return 0;
}