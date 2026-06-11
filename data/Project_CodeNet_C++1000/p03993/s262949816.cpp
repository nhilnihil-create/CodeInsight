#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long int
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    int a;
    rep(i, N) {
        cin >> a;
        A[i] = a-1;
    }

    int ans = 0;
    rep(i, N) {
        int j = A[i];
        if (A[j] == i) ans++;
    }

    cout << ans / 2 << endl;

    return 0;
}
