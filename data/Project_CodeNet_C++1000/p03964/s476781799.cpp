#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int64_t N;
    cin >> N;

    int64_t T, A;
    cin >> T >> A;
    while(--N) {
        int64_t t, a;
        cin >> t >> a;
        int64_t mul = max((T+t-1)/t, (A+a-1)/a);
        T = t*mul;
        A = a*mul;
    }

    cout << T+A << endl;
    return 0;
}
