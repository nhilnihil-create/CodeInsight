#include <iostream>
using namespace std;

int main() {
    int N = 0, K = 0;
    cin >> N >> K;
    int point = 0;
    int sum = 0;

    for(int i = 0; i < N; i++) {
        cin >> point;
        if(point < K - point) {
            sum += 2 * point;
        } else {
            sum += 2 * (K - point);
        }
    }
    cout << sum << endl;
}