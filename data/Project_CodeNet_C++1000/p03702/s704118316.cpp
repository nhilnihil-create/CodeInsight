#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int64_t A, B;
    cin >> N >> A >> B;
    vector<int64_t> h(N);
    for(int i=0; i<N; i++) {
        cin >> h[i];
    }

    A -= B;

    int64_t ng = -1, ok = 1'000'000'000L;
    while(ng + 1 < ok) {
        int64_t mid = (ok + ng) / 2;
        int64_t tmp = 0;
        for(int i=0; i<N; i++) {
            tmp += (max(h[i] - mid*B, 0L) + A-1) / A;
        }
        if(tmp <= mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}
