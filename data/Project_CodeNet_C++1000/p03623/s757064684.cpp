#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x;
    int a;
    int b;
    cin >> x >> a >> b;
    int ab = abs(x - a);
    int ba = abs(x - b);
    if(ab < ba){
        cout << "A" << endl;
    }
    else{
        cout << "B" << endl;
    }
}