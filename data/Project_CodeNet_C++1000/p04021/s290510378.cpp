#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]] = i;
    }
    vector<int> B = A;
    sort(B.begin(), B.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (abs(i - mp[B[i]]) % 2 == 1) {
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
}
