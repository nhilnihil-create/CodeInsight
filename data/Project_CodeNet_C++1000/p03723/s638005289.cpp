#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

const double PI=acos(-1);

int main(){
    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    while(a%2 == 0 && b%2 == 0 && c%2 == 0){
        if(a == b && b == c){
            sum = -1;
            break;
        }
        int aa = a/2, bb = b/2, cc = c/2;
        a = bb+cc;
        b = aa+cc;
        c = aa+bb;
        sum++;
    }

    cout << sum << endl;
    return 0;
}