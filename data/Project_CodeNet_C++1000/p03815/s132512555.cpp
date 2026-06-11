#include <iostream>

using namespace std;

int main() {
    long long int x;
    cin >> x;
    
    if(x<=6) {
        cout << 1 << endl;
    } else if(x<=11) {
        cout << 2 << endl;
    } else {
        if(x%11==0) {
            cout << x*2/11 << endl;
        } else if(x%11<=6) {
            cout << (x/11)*2+1 << endl;
        } else {
            cout << (x/11)*2+2 << endl;
        }
    }


    return 0;
    
}