#include <iostream>

using namespace std;

int main()
{
    int A,B,C,D,R1,R2;
    cin >> A >> B >> C >> D;
    R1 = A * B;
    R2 = C * D;
    if (R1 > R2) cout << R1;
    else if (R1 < R2) cout << R2;
    else cout << R1;

    return 0;
}
