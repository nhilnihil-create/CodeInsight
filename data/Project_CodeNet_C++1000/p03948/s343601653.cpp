#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    bool change = false;
    int m = INT_MAX;
    int diff = 0;
    int pairs = 0;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        if (m > a) {
            m = a;
            change = true;
        } else { // m < a
            if (diff < abs(a - m)) {
                diff = abs(a - m);
                pairs = 1;
                change = false;
            } else if (diff == abs(a - m) && change) {
                pairs++;
                change = false;
            }
        }

    }

    cout << pairs << endl;

    return 0;
}