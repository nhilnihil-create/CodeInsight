#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long x,y;
    long long z;
    cin >> x >> y;
    long long A = x * y;
    if (A < 0){
        if (x < 0){
            if (abs(x) <= abs(y)){
                z = x + y + 1;
            }
            else {
                z = - x - y + 1;
            }
        }
        else {
            if (abs(x) >= abs(y)){
                z = x + y + 1;
            }
            else {
                z = - x - y + 1;
            }
        }
    }
    else {
        if (y > x){
            z = y - x;
        }
        else {
            if (x == 0){
                z = abs(y) + 1;
            }
            else if (y == 0){
                z = abs(x) + 1;
            }
            else {
                z = x - y + 2;
            }
        }
    }
    cout << z << endl;
}