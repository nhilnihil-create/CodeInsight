#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long k;
const long long n = 50;
vector<long long> a(55, 0);
vector< vector<long long> > pmvec(50, vector<long long>(50, 0));

int main() {
    cin >> k;
    long long now = 1;
    for(int i = 0; i < n; ++i) {
        long long check = n-i;
        for(int j = 0; j < i+1; ++j) {
            pmvec.at(i).at(j) = -check;
        }
        for(int j = i+1; j < n; ++j) {
            pmvec.at(i).at(j) = now;
        }
        now++;
    }

    long long cnt = k/n;
    long long rest = k%n;

    // cout << cnt << " " << rest << endl;
    vector<long long> ans(55, 0);
    for(int i = 0; i < n; ++i) {
        ans.at(i) += pmvec.at(49).at(i)*cnt;
        if(rest != 0) ans.at(i) += pmvec.at(rest-1).at(i);
    }

    vector<long long> sum(55, 49);
    for(int i = 0; i < n; ++i) {
        sum.at(i) -= ans.at(i);
    }

    cout << n << endl;

    for(int i = 0; i < n; ++i) {
        cout << sum.at(i) << " ";
    }
}