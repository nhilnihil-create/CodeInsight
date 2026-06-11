#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string A;

int main() {
    cin >> A;
    long long alen = A.length();

    long long ans = alen*(alen-1) / 2;
    map<char, long long> mcnt;
    for(int i = 0; i < alen; ++i) {
        mcnt[A.at(i)]++;
    }

    long long subcnt = 0;
    for(auto x : mcnt) {
        long long cc = x.second;
        subcnt += (cc*(cc-1)) / 2;
    }

    cout << ans-subcnt+1 << endl;
}