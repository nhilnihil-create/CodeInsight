#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int ans = pow(10, 9);

    int N;
    cin >> N;

    vector<int> a(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = -100; i <= 100; i++) {
        int c = 0;
        for(int j = 0; j < N; j++) {
            c += (i - a[j]) * (i - a[j]);
        }
        ans = min(ans, c);
    }

    cout << ans << endl;
}