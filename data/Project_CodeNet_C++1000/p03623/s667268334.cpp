#include <iostream>
using namespace std;

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    if ( (x-a)*(x-a) > (x-b)*(x-b) ){
        cout << "B" << endl;
    }
    else {
        cout << "A" << endl;
    }
}