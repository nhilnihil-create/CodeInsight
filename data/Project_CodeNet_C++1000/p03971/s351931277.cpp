#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    int rank_A = 0;
    int rank_B = 0;
    for (int i = 0; i < N; i++) {
        if ((rank_A + rank_B) >= A + B) {
            cout << "No" << endl;
        } else if (S[i] == 'a') {
            cout << "Yes" << endl;
            rank_A++;
        } else if (S[i] == 'b') {
            if (rank_B < B) {
                cout << "Yes" << endl;
                rank_B++;
            } else {
                cout << "No" << endl;
            }
        } else if (S[i] == 'c') {
            cout << "No" << endl;
        }
    }
    return 0;
}

