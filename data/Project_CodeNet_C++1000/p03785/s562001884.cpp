#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N, C, K;
    cin >> N >> C >> K;
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end(), greater<int64_t>());
    int64_t sum_bus_count = 1;
    int64_t til_can_wait = vec[0] - K;
    int64_t ninzuu = 1;
    for (int64_t i=1; i<N; i++) {
        int64_t time = vec[i];
        if (til_can_wait > time || ninzuu >= C) {
            sum_bus_count += 1;
            til_can_wait = time - K;
            ninzuu = 1;
        } else {
            ninzuu += 1;
        }
    }

    cout << sum_bus_count << endl;
    return 0;
}