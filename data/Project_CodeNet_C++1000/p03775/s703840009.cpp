#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    long N;
    cin >> N;

    long minimun = 10000;
    long f = 100;
    for (long i = 1; i * i < N+1; i++) {
        long A = i;
        long B = (long)N/A;
        if (N%A != 0) {
            continue;
        }

        long digit_A = 0;
        while (A > 0) {
            A = A/10;
            digit_A++;
        }

        long digit_B = 0;
        while (B > 0) {
            B = B/10;
            digit_B++;
        }
        f = digit_A;

        if (f < digit_B) {
            f = digit_B;
        }

        if (minimun > f) {
            minimun = f;
        } 
    }
    cout << minimun << endl;
}