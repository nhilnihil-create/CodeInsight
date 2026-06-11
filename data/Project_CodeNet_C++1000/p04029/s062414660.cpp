#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    int numOfCandy = 0;
    rep(i, N) {
        numOfCandy += i + 1;
    }
    cout << numOfCandy << endl;

    return 0;
}