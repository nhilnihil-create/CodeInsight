#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long N, K;
    cin >> N >> K;
    cout << K * (long)pow(K-1, N-1) << endl;
    return 0;
}