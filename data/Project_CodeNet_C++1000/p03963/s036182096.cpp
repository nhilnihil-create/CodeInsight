#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int s = 1;
    for (int i = 0; i < N; i++) {
        if (!i) {
            s *= K;
        }
        else {
            s *= (K - 1);
        }
    }

    cout << s << endl;
}