#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w, a, b;
    cin >> w >> a >> b;
    if(a+w<b){
        cout << b - a - w << endl;
        return 0;
    }
    if(a > b + w){
        cout << a - b - w << endl;
        return 0;
    }
    if(b<=a+w&&b>=a||a <= b+w &&a >= b){
        cout << 0 << endl;
        return 0;
    }
}