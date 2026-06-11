#include <iostream>
using namespace std;
int main(void) {
int A, B, wa;

cin >> A;
cin >> B;
wa = A + B;
if ( wa >= 24 ) {
    wa = wa - 24;
    cout << wa << endl;
} else {
    cout << wa << endl;
}

return 0;
}