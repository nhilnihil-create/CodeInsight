#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T.at(i);
    sort(T.begin(), T.end());

    int bus = 0;
    int passenger = 0;
    int time;
    for (int i = 0; i < N; i++) {
        if (passenger == 0 || T.at(i) - time > K || passenger + 1 > C) {
            bus++;
            passenger = 1;
            time = T.at(i);
        } else passenger++;
    }
    cout << bus << endl;
}
