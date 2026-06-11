#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    int64_t sum = 0;
    vector<pair<int64_t, int64_t>>vec(N);
    for (int64_t i=0; i<N; i++) {
        int64_t a, b;
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }

    for (int64_t i=N-1; i>=0; i--) {
        int64_t a = vec[i].first;
        int64_t b = vec[i].second;
        int64_t now = a + sum;
        if (now % b != 0) {
            int64_t c = now / b;
            sum += (b * (c + 1)) - now;
        }
    }

    cout << sum << endl;
    return 0;
}