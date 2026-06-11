#include <iostream>
using namespace std;

int main(void) {
    int X,A,B;cin>>X>>A>>B;
    if (B - A <= 0) cout << "delicious" << endl;
    else if (B - A > 0 && B - A <= X) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return 0;
}