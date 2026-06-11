#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> s(N);
    int sum = 0;

    for(int i = 0; i < N; i++) {
        cin >> s[i];
        sum += s[i];
    }

    if(sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < N; i++) {
        if(s[i] % 10 != 0) {
            cout << sum - s[i] << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}