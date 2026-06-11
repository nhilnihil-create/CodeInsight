#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b;
    char op;
    
    cin >> a >> op >> b;

    switch (op) {
        case '+':
            cout << a + b << endl;
            break;
        
        default:
            cout << a - b << endl;
            break;

    }
}