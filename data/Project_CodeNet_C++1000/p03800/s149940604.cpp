#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    
    vector<char> t(N);
    vector<char> animal = {'S', 'W'};
    rep(i, 2) rep(j, 2) {
        t[0] = animal[i];
        t[1] = animal[j];
        REP(k, N - 1) {
            if (t[k] == 'S') {
                if (s[k] == 'o') t[k + 1] = t[k - 1];
                else t[k + 1] = 'S' + 'W' - t[k - 1];
            } else {
                if (s[k] == 'x') t[k + 1] = t[k - 1];
                else t[k + 1] = 'S' + 'W' - t[k - 1];
            }
        }
        bool judge = true;
        if (t[0] == 'S') {
            if (s[0] == 'o' ^ t[1] == t[N - 1]) judge = false;
        } else {
            if (s[0] == 'x' ^ t[1] == t[N - 1]) judge = false;
        }
        if (t[N - 1] == 'S') {
            if (s[N - 1] == 'o' ^ t[0] == t[N - 2]) judge = false;
        } else {
            if (s[N - 1] == 'x' ^ t[0] == t[N - 2]) judge = false;
        }
        if (judge) {
            rep(i, N) cout << t[i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
