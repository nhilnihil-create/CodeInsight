#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    unsigned int N;
    cin >> N;

    vector<int> T_r(N), A_r(N);
    for (int i = 0; i < N; i++) {
        cin >> T_r[i] >> A_r[i];
    }

    ull T_c = 1, A_c = 1;
    for (int i = 0; i < N; i++) {
        ull k = max((T_c + T_r[i] - 1) / T_r[i], (A_c + A_r[i] - 1) / A_r[i]);
        T_c = T_r[i] * k;
        A_c = A_r[i] * k;
        // cout << k << " " << T_c << " " << A_c << endl;
    }

    cout << T_c + A_c << endl;

    return 0;
}
