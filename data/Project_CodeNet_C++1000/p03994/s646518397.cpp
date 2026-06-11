#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;

    for (int i = 0; i < S.size(); ++i) {
        int con = ((int)('a' - S[i]) + 26) % 26;
        if (con <= K) {
            S[i] = 'a';
            K -= con;
        }

        if (i == (int)S.size()-1) {
            K %= 26;
            S.back() += K;
        }
    }
    cout << S << endl;
}
