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

int main() {
    string S; cin >> S;
    int N = S.length();
    int gs = 0, ps = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'p') ps++;
        else gs++;
    }
    cout << (gs-ps)/2 << endl;
}
