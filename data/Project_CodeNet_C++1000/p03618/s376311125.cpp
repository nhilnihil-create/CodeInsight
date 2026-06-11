#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1000000007;

int main() {
    string a;
    cin >> a;
    int n = a.length();
    
    int cnt[26];
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        int c = a[i] - 'a';
        cnt[c]++;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += (ll)cnt[i] * (n - cnt[i]);
    }

    ans /= 2;
    ans++;

    cout << ans << endl;
    return 0;
}