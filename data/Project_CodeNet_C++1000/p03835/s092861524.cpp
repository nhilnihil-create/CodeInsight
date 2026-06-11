#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int K, S;
    cin >> K >> S;
    int64_t count = 0;
    for (int x=0; x<=K; x++) {
        for (int y=0; y<=K; y++) {
            int sum_ = x + y;
            if (sum_ <= S && (S - sum_) <= K) {
                count += 1;
            }

            if (sum_ > S) {
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}