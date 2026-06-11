#include <iostream>
using namespace std;
int main(void){
    int a,b;
    char aa,bb;
    cin >> aa >> bb;
    a = aa == 'H' ? 1 : 0;
    b = bb == 'H' ? 1 : 0;
    int ans = a ^ b;
    if(!ans){
        cout << "H" << endl;
    }
    else{
        cout << "D" << endl;
    }
}
