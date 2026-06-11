#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;

    vector<map<int, ll> > m(N + 1);

    m[0][0] = 1;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        for(int j = i; j >= 0; j--) {
            for(auto k = begin(m[j]); k != m[j].end(); k++) {
                m[j + 1][x + k -> first] += k -> second;
            }
        }
    }

    ll ans = 0;

    for(int i = 1; i <= N; i++) {
        ans += m[i][A * i];
    }

    cout << ans << endl;
}