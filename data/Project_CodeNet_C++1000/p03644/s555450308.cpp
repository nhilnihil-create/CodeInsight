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
    int x, y,w=0,a;
    cin >> x;
    if (x == 1)
        cout << 1;
    else {
        for (int i = x; i >= 1; i--) {
            int  z = 0;
            y = x;
            while (y > 0) {

                if (y % 2 == 0) {
                    z++;
                }

                y /= 2;
            }
            if (z > w) {
                a = i;
                w = z;
            }x--;
        }
        cout << a;
    }
    return 0;
}