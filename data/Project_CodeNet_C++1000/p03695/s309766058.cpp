#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int rate[9] = {};
    int a;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a >= 3200) a=3200;
        rate[a/400]++;
    }
    int sum = 0;
    for (int i=0; i<8; i++) {
        if (rate[i] != 0) sum++;
    }
    int min, max;
    max = sum + rate[8];
    if (sum != 0) {
        min = sum;
    } else {
        if (rate[8] != 0) {
            min = 1;
        } else {
            min = 0;
        }
    }
    cout << min << " " << max << endl;
}