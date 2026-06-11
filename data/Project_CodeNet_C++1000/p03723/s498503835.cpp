#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    while (true) {
        if ((A % 2 == 1) || (B % 2 == 1) || (C % 2 == 1)) {
            break;
        }
        if ((A == B) || (B == C) || (C == A)) {
            ans = -1;
            break;
        }
        int temp_A = A;
        int temp_B = B;
        int temp_C = C;
        A = (temp_B / 2) + (temp_C / 2);
        B = (temp_A / 2) + (temp_C / 2);
        C = (temp_A / 2) + (temp_B / 2);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
