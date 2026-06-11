#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, C, K;
    cin >> N >> C >> K;

    vector<int> time(N);
    rep(i, N) cin >> time[i];

    sort(time.begin(), time.end());

    int bus_num = 0, wait_start = 0, wait_people = 0;
    rep(i, N) {
        if (wait_people > 0 && time[i] - wait_start > K) {
            bus_num++;
            wait_people = 0;
        }

        if (wait_people == 0) wait_start = time[i];
        wait_people++;
        
        if (wait_people == C) {
            bus_num++;
            wait_people = 0;
        }
    }

    if (wait_people > 0) bus_num++;

    cout << bus_num << endl;

    return 0;
}