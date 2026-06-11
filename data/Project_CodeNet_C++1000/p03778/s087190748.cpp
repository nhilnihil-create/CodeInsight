#include <iostream>

using namespace std;

int main(){
    int w, a, b, _a, _b;

    cin >> w >> a >> b;
    _a = a + w;
    _b = b + w;

    if(_b < a){
        cout << a - _b << endl;
    }else if(b > _a){
        cout << b - _a << endl;
    }else{
        cout << 0 << endl;
    }
}