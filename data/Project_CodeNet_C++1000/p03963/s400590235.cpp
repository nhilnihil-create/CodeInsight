#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    cout << long(K * pow(K - 1, N - 1)) << endl;
}