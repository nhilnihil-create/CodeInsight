#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int64_t> a_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> a_vec.at(i);
    int64_t min_cost = -1;
    for (int i = 1; i < (1 << N); ++i) {
        bitset<15> visible(i);
        if (static_cast<int>(visible.count()) != K)
            continue;
        int64_t prev_hight = 0;
        int64_t cost = 0;
        for (int j = 0; j < N; ++j) {
            int64_t hight = a_vec.at(j);
            if (visible.test(j) == 1 && hight <= prev_hight) {
                cost += prev_hight + 1 - hight;
                hight = prev_hight + 1;
            }
            prev_hight = max(prev_hight, hight);
        }
        if (min_cost == -1 || min_cost > cost)
            min_cost = cost;
    }
    cout << min_cost << endl;
}

