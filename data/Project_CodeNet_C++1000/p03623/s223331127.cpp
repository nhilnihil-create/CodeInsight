#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;
int main() {
    int x, a, b;
    cin >> x >> a >> b;
    int y = abs(a - x);
    int z = abs(b - x);
    if (y < z)
        cout << "A";
    else
        cout << "B";


    return 0;
}
