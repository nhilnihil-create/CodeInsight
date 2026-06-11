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

    int n;
    cin >> n;

    int k = 1;
    while(k * (k + 1) / 2 < n) {
        ++k;
    }

    int target = n - k;
    vector<int> Ans;
    Ans.push_back(k);
    for (int i = k - 1; i > 0; --i) {
        if (target == 0) break;
        if (target - i < 0) {
            continue;
        } else {
            Ans.push_back(i);
            target -= i;
        }
    }

    for (auto itr = Ans.begin(); itr != Ans.end(); ++itr) {
        cout << *itr << endl;
    }

    return 0;
}