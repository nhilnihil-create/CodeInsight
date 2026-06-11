#include <iostream>
#include <vector>
using namespace std;

const int up = 1;
const int flat = 0;
const int down = -1;

int main() {
    uint N;
    cin >> N;
    vector<int> A(N, 0);
    for (auto &a: A) cin >> a;

    int split = 1;
    int direction = flat;
    for (size_t i=0; i<A.size()-1; ++i) {
        if (A[i] > A[i+1]) {
            if (direction == up) {
                ++split;
                direction = flat; // まだわからない
            }
            else if (direction == flat) {
                direction = down;
            }
        }
        else if (A[i] < A[i+1]) {
            if (direction == down) {
                ++split;
                direction = flat;
            }
            else if (direction == flat) {
                direction = up;
            }
        }
    }
    cout << split << endl;
}