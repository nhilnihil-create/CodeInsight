#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define llong long long int
#define ullong unsigned long long int
#define rep(i, n) for (int i = 0; i < n; ++i)

const static long long int MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    cout << S.substr(0, 4) << " " << S.substr(4, 8) << endl;

    return 0;
}