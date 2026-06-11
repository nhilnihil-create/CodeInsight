#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    map<int, int> A;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }

    int cnt = 0;
    for (auto x : A) {
        if (x.second % 2 != 0) {
            cnt++;
        }
    }

    cout << cnt << endl;
}