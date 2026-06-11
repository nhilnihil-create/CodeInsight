#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    char op;
    cin >> A >> op >> B;
    
    if(op == '+') A += B;
    if(op == '-') A -= B;

    cout << A << endl;
}
