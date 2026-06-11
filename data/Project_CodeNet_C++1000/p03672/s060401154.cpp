#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), mx = INT_MIN;
    loop(mid, n/2) {
        int next_start = mid, count = 0;
        for(int i = 0; i < mid; i++) {
            if(s[i] == s[next_start]) {
                count++;
                next_start++;
            } else {
                mx = max(mx, count);
                break;
            }
            // cout << s[i] << " " << s[next_start] << " " << count << endl;
        }
        mx = max(mx, count);
        // cout << mid << " " << mx << endl;
    }
    cout << 2*mx << endl;
    return 0;
}
