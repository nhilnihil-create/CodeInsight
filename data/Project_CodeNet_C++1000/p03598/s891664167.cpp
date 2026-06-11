#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    int x[N];

    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < N; i++) {
        int a_sa = x[i];
        int b_sa = K - x[i];

        int taishou_sa = min(a_sa, b_sa);

        sum = sum + (2 * taishou_sa);

    }

    cout << sum << endl;


    return 0;

}



