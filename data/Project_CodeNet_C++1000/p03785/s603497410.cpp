#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

size_t pickup(size_t next, vector<int>& T, int C, int K) {
    int start = T[next] + K;
    int people = 0;
    while (T[next] <= start && next<T.size()) {
        ++people; // pick up
        ++next; // next index
        if (people == C) {
            break;
        }
    }
    return next;
}

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (auto &x: T) cin >> x;

    sort(T.begin(), T.end());
    int bus = 0;
    int next=0;
    while (next < T.size()) {
        next = pickup(next, T, C, K);
        ++bus;
    }
    cout << bus << endl;
}