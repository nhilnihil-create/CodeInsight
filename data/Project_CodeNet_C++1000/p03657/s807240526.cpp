#include <bits/stdc++.h>
using namespace std;

bool possible(int a) {
    return (a > 1) && ((a % 3) == 0);
}
int main(void) {
    int A,B;
    cin >> A >> B;

    if(possible(A) || possible(B) || possible(A+B) ) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
