#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t A, B, C;
    cin >> A >> B >> C;
    if (A == B && B == C && A % 2 == 0) {
        cout << "-1" << endl;
    } else {
        int count = 0;
        while (true) {
            if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) {
                break;
            }

            int tmp_a = A / 2;
            int tmp_b = B / 2;
            int tmp_c = C / 2;
            A = tmp_b + tmp_c;
            B = tmp_a + tmp_c;
            C = tmp_a + tmp_b;
            count += 1;
        }

        cout << count << endl;
    }
    return 0;
}