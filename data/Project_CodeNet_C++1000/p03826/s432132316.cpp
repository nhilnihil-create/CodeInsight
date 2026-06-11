#include <iostream>
using namespace std;

int A,B,C,D,Area1,Area2;
int main() {
    cin >> A >> B >> C >> D;

    Area1=A*B;
    Area2=C*D;

    if(Area1>Area2){
        cout << Area1 << endl;
    }
    else if(Area1==Area2){
        cout << Area1 << endl;
    }
    else{
        cout << Area2 << endl;
    }
    return 0;
}
