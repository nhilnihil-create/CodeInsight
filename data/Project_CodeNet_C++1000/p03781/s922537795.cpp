#include <iostream>

using namespace std;

int main(void) {
    int X;
    cin >> X;

    for(int64_t i=1; i<=X; i++) {
        if(i*(i+1)/2 >= X) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
