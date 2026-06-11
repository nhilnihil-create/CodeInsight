#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n, x;
vector<long long> a(100100, 0);

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    long long cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(i == n-1) {

        }else {
            long long sum = a.at(i) + a.at(i+1);
            if(sum > x) {
                long long rest = sum - x;
                if(a.at(i+1) >= rest) {
                    a.at(i+1) -= rest;
                }else {
                    a.at(i+1) = 0;
                }
                cnt += rest;
            }
        }
    }
    cout << cnt << endl;
}