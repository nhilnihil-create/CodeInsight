#include <iostream>

using namespace std;

int main(){

    int n1, n2, n3, p1, p2, p3;

    cin >> n1 >> n2 >> n3;

    p1 = n1 + n2;
    p2 = n2 + n3;
    p3 = n1 + n3;

    if(p1 <= p2 && p1 <= p3){
        cout << p1 << endl;
    }
    else if(p2 <= p1 && p2 <= p3){
        cout << p2 << endl;
    }
    else{
        cout << p3 << endl;
    }

    return 0;
}
