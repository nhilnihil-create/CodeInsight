#include <iostream>  
#include <string.h> 
using namespace std;
int main() {
    int a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    
    for (int i = 1; i < 3; i++) {
        int min = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                min = a[j];
                a[j] = a[i];
                a[i] = min;
            }

        }
    }
    
        cout << a[0]+a[1];
    

    return 0;
}
 
