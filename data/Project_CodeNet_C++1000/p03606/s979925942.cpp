#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;

    for(int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        ans += r - l + 1;
    }

    cout << ans << endl;
}