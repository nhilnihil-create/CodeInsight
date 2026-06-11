#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int X;
    cin >> X;

    int n=0,i=0;
    while(n<X){
        i++;
        n += i;
    }
    cout << i << endl;
}