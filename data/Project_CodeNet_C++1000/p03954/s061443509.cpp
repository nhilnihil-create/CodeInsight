#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool solve(const vector<int> &a, int x) {
    deque<int> b;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] >= x) b.push_back(1);
        else b.push_back(0);
    }
    b.push_front(b[0]);
    b.push_back(b.back());
    
    int mid = b.size() / 2;
    int left, right;
    for (int i = mid - 1; i >= 0; --i) {
        if (b[i] == b[i+1]) {
            left = i;
            break;
        }
    }
    for (int i = mid + 1; i  < b.size(); ++i) {
        if (b[i-1] == b[i]) {
            right = i;
            break;
        }
    }
    if (right - mid >= mid - left) return b[left];
    else return b[right];
}

int main() {
    int N, K; cin >> N;
    vector<int> a(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; ++i) cin >> a[i];

    int low = 0, high = N*2;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (solve(a, mid)) low = mid;
        else high = mid;
    }
    cout << low << endl;
}
