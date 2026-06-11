#include <iostream>
#include <vector>
#include <algorithm>
// #include <map>
// #include <cmath>
// #include <string>

using namespace std;
typedef long long ll;


int pow_mod(int x, int a) {
    if (a == 0) return 1;
    return ((ll)pow_mod(x, a-1) * x) % 1000000007;
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    bool possible = true;
    if (A.size() % 2 == 0) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != (i/2)*2 + 1) {
                possible = false;
                break;
            }
        }
    } else {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != ((i+1)/2)*2) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << pow_mod(2, A.size() / 2) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
