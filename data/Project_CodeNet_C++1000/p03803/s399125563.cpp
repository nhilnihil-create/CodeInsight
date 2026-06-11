#include <iostream>
using namespace std;

// Caleb Faith Adnaka XI105
int main() {

    int A,B;
    cin >> A >> B;
    
    if (A == B){
        cout << "Draw\n";
    }
    else if (A > B && B != 1 || A == 1){
        cout << "Alice\n";
    }
    else if (B > A && A != 1 || B == 1){
        cout << "Bob\n";
    }

}