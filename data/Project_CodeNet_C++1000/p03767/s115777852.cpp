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
    vector<int64_t>vec(3*N);
    for (int64_t i=0; i<3*N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    int64_t sum = 0;
    for (int64_t i=N; i<N+N; i++) {
        sum += vec[i];
    }

    bool guusuu = (N % 2 == 0);
    int64_t kouho = 0;
    for (int64_t i=3*N-1; i>=N; i--) {
        if (guusuu && i%2==0) {
            kouho += vec[i];
        } else if (!guusuu && i%2!=0) {
            kouho += vec[i];
        }
    }

    cout << max(sum, kouho) << endl;
    return 0;
}