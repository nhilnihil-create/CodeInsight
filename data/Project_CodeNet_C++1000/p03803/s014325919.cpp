#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a == b) puts("Draw");
    else if(b != 1 && b < a || a == 1) puts("Alice");
    else puts("Bob");
    return 0;
}
