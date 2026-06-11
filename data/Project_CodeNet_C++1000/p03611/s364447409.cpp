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
    map<int64_t,int64_t>d;
    for (int64_t i=0; i<N; i++) {
        int64_t n;
        cin >> n;
        if (d.count(n) > 0) {
            d[n] = d[n] + 1;
        } else {
            d[n] = 1;
        }
    }

    int64_t max_count = 0;
    for (auto s : d) {
        int64_t b_v = 0;
        if (d.count(s.first-1) > 0) {
            b_v = d[s.first-1];
        }

        int64_t a_v = 0;
        if (d.count(s.first+1) > 0) {
            a_v = d[s.first+1];
        }

        int64_t count = a_v + b_v + s.second;
        if (count > max_count) {
            max_count = count;
        }
    }

    cout << max_count << endl;
    return 0;
}