#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
    }

    deque<int> deq;

    // 全体が偶数
    if (N % 2 == 0) {
        for (int i = 0; i < N; i++) {
            if ((i + 1) % 2 == 0) {
                deq.push_front(A[i]);
            } else {
                deq.push_back(A[i]);
            }
        }
    }
    // 全体が奇数
    else {
        for (int i = 0; i < N; i++) {
            if ((i + 1) % 2 == 0) {
                deq.push_back(A[i]);
            } else {
                deq.push_front(A[i]);
            }
        }
    }

    rep(i, N) {
        cout << deq[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
}