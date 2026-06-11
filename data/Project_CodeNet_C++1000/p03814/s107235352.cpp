#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
    string x; int a = -1, b = 0;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'A' && a == -1) {
            a = i;
        }
        if (x[i] == 'Z' && a != -1)
            b = i;
    }
    cout << b - a + 1;
    return 0;
}