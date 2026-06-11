#include <iostream>

using namespace std;

int main (void) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && a < c){
        if(b < c){
            cout << a + b << endl;
        }else{
            cout << a + c << endl;
        }
    }else if(b < a && b < c){
        if(c < a){
            cout << b + c << endl;
        }else{
            cout << b + a << endl;
        }
    }else{
        if(a < b){
            cout << c + a << endl;
        }else{
            cout << c + b << endl;
        }
    }

    
    return 0;
}
