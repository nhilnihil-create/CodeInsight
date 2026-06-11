#include <iostream>
using namespace std;
int main(void){
    int A,B,C;
    cin >> A >> B >> C;
    if (A-C<=0){
        if (B-C>=0){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    
}
