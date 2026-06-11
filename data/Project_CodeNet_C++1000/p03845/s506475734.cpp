#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) cin >> values[i];
    for (int i = 1; i < N; ++i) values[i] += values[i-1];
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int pos, delta;
        cin >> pos >> delta;
        pos--;
        if (pos == 0) {
            cout << (values[pos] > delta ? values[N-1] - (values[0] - delta) :
                    values[N-1] + (delta - values[0])) << '\n';
        }
        else {
            if (values[pos] - values[pos-1] < delta) {
                cout << (values[N-1] + delta - (values[pos] - values[pos-1])) << '\n';
            }
            else {
                cout << (values[N-1] - (values[pos] - values[pos-1] - delta)) << '\n';
            }
        }
    }
}
