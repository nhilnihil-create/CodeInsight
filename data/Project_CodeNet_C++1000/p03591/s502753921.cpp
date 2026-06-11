#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.size() < 4) {
        cout << "No" << endl;
        return 0;
    }
    
    if (S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
