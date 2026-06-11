#include <iostream>

using namespace std;

int main() {
    int a, b, W;
    cin >> W >> a >> b;
    if(a<b) {
        if(a+W>=b) {
            cout << 0 << endl;
        } else {
            cout << b-a-W << endl;
        }
    } else if(b<a) {
        if(b+W>=a) {
            cout << 0 << endl;
        } else {
            cout << a-b-W << endl;
        }
    } else {
        cout << 0 << endl;
    }



    return 0;
    
}