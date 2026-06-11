#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    string s, t;
    cin >> N >> s >> t;
    
    reverse(s.begin(), s.end());
    for (int i = N; i >= 0; --i) {
        string str = s.substr(0, i);
        reverse(str.begin(), str.end());
        if (str == t.substr(0, i)) {
            cout << 2 * N - i << endl;
            return 0;
        }
    }
    return 0;
}
