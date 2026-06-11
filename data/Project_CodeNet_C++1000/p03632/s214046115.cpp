#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A<C) {
        cout << max(min(B, D)-C, 0) << endl;
    } else {
        cout << max(min(B, D)-A, 0) << endl;
    }


    return 0;
    
}