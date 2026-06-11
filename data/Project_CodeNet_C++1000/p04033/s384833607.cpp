#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    if (a <= b && 0 < a)
        cout << "Positive";
    else if (a < 0 && b < 0){
        if ((a - b) % 2 == 0)
            cout << "Negative";
        else
            cout << "Positive";
    }
    else if(a <= 0 && 0 <= b)
        cout << "Zero";
    
    return 0;
}