#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, sum = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        int left, right; cin >> left >> right;
        sum += (right - left) + 1;
    }
    printf("%d\n", sum);
}
