#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[a[i]] == i) {
            ans++;
        }
    }
    cout << ans / 2 << endl;
}
