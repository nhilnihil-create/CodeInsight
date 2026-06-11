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
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    int64_t b_n = vec[0];
    int s = 0;
    int64_t splited = 1;
    for (int64_t i=1; i<N; i++) {
        int64_t n = vec[i];
        if (s == 0) {
            if (n > b_n) {
                s = 1;
            } else if (n < b_n) {
                s = -1;
            }
        } else if (s == 1) {
            if (n >= b_n) {
            } else {
                splited += 1;
                s = 0;
            }
        } else {
            if (n <= b_n) {
            } else {
                splited += 1;
                s = 0;
            }
        }

        b_n = n;
    }

    cout << splited << endl;
    return 0;
}