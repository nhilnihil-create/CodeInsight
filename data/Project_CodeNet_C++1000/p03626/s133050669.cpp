#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

int N;
string S1, S2;

ll res = 1;
ll D = 1e9+7;

ll solve(int k, int pattern) {
    if (k >= N) return 1;
    if (S1[k] == S2[k]) {
        if (!pattern) {
            return 2 * solve(k+1,0) % D;
        } else {
            return solve(k+1,0) % D;
        }
    } else {
        if (!pattern) {
            return 2 * solve(k+2,1) % D;
        } return 3 * solve(k+2,1) % D;
    }
}

int main() {
    cin >> N;
    cin >> S1 >> S2;

    if (S1[0] == S2[0]) {
        res = 3 * solve(1,0) % D;
    } else {
        res = 6 * solve(2,1) % D;
    }
    cout << res << endl;


    
}
