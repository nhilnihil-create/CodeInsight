#include <bits/stdc++.h>

using namespace std;

int main() {
    uint64_t N, C, K;
    cin >> N >> C >> K;
    vector<uint64_t> T(N);
    for (uint64_t& t : T) {
        cin >> t;
    }
    sort(T.begin(), T.end());
    
    uint64_t num_buses = 0;
    uint64_t time_limit = T[0] + K;
    uint64_t num_people = 0;
    
    for (uint64_t i = 0; i < N; i++) {
        if (T[i] <= time_limit && num_people < C) {
            num_people++;
        } else {
            num_buses++;
            num_people = 1;
            time_limit = T[i] + K;
        }
    }
    if (num_people > 0) {
        num_buses++;
    }
    cout << num_buses;
    return 0;
}
