#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, P;
    cin >> N >> P;
    vector<vector<int64_t>>vec(N+1, vector<int64_t>(5001, 0));
    vector<int64_t>retsu(N);
    for (int i=0; i<N; i++) {
        cin >> retsu.at(i);
    }

    vec[0][0] = 1;
    for (int i=1; i<=N; i++) {
        int num = retsu[i-1];
        for (int j=0; j<5001; j++) {
            if (j - num >= 0) {
                vec[i][j] += vec[i-1][j-num];
            }

            vec[i][j] += vec[i-1][j];
        }
    }

    int64_t count = 0;
    for (int i=0; i<5001; i++) {
        if (vec[N][i] > 0 && i % 2 == P) {
            count += vec[N][i];
        }
    }

    cout << count << endl;
    return 0;
}