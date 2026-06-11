#include <iostream>

using  namespace std;


int main (void) {

    int x, a, b;

    cin >> x >> a >> b;
    
    if (b - a <= 0){
        cout << "delicious" << endl;
    }else if (b - a >= x + 1) {
        cout << "dangerous" << endl;
    }else if (b - a <= x ){
        cout << "safe" << endl;
    }

    return 0;
}
