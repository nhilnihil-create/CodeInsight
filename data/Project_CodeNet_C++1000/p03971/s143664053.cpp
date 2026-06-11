#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int a_count = 0;
    int b_count = 0;
    string S;
    cin >> S;
    int sum_passes = A + B;
    for (int i=0; i < N; i++) {
        if (S[i] == 'c') {
            cout << "No" << endl;
            continue;
        }

        if (S[i] == 'a') {
            if (a_count + b_count < sum_passes) {
                a_count += 1;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (S[i] == 'b') {
            if (a_count + b_count < sum_passes && b_count < B) {
                b_count += 1;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}