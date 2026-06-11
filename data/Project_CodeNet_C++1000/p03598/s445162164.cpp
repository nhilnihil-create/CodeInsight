#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    int K;
    cin >> N >> K;
    int count = 0;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        int distA = x;
        int distB = K - x;
        if (distB < 0) distB = -distB;
        if (distA < distB) {
            count += 2 * distA;
        } else {
            count += 2 * distB;
        }
    }
    cout << count << endl;



}