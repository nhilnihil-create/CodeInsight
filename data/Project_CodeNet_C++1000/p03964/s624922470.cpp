#include <iostream>

using namespace std;

void fix(unsigned long & LC, unsigned long & LA, unsigned long RT, unsigned long RA);

int main () {

    unsigned long N, T, A, CT, CA;
    cin >> N;

    cin >> CT >> CA;

    while (--N > 0) {
        cin >> T >> A;
        fix(CT, CA, T, A);
    }

    cout << CT + CA << endl;

    return 0;
}

void fix(unsigned long & LT, unsigned long & LA, unsigned long RT, unsigned long RA) {
    unsigned long mt = LT/RT, ma = LA/RA;
    if (LT % RT != 0) mt++;
    if (LA % RA != 0) ma++;
    unsigned long m = mt > ma ? mt : ma;
    
    LT = m * RT;
    LA = m * RA;
}
