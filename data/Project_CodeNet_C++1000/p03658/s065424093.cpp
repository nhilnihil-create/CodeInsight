#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> l(N);

    for(int i = 0; i < N; i++) cin >> l[i];

    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;

    for(int i = 0; i < K; i++) ans += l[i];

    cout << ans << endl;
}