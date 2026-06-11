#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    int N, L;
    cin >> N >> L;

    vector<string> vec(N);
    rep(i, N) {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    rep(i, N) {
        cout << vec.at(i);
    }
    return 0;
}