#include <iostream>
#include <bitset>
using namespace std;

int main() {
    
    int a, b;
    string op;
    cin >> a >> op >> b;

    int ans;

    if(op == "+"){
        ans = a + b;
    }
    else if(op == "-"){
        ans = a - b;
    }



    cout << ans << endl;

    return 0;

}



