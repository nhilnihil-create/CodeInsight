#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9

typedef long long ll;

using namespace std;

const int mod = 1e9+7;
const int N = 1e5+5;
int a[N];

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    string t = "CODEFESTIVAL2016";
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] != t[i]) ans++;
    }

    cout << ans;

    return 0;
}
