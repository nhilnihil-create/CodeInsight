#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    string T = S;
    reverse(T.begin(), T.end());
    if (S == T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
