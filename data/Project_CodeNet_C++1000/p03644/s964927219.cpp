#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    // N以下の最大の2のべき乗を求める
    int thresh = 1;
    int k = 0;
    while (thresh <= N) {
        thresh *= 2;
        ++k;
    }
    cout << thresh / 2 << endl;
}
