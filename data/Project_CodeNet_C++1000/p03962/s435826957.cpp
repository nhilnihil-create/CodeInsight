#include <iostream>  
#include <string.h> 
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c ;
    if (a == b&&b == c)
        cout << 1;
    else if (a != b && b != c && c != a)
        cout << 3;
    else 
        cout<<2;
    return 0;
}
 
