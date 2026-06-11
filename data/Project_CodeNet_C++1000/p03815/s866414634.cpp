#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
          
int main() {
    long long int x;
    cin >> x;
    long long int a = x % 11;
    if( a > 0 && a < 7 ){
        cout << (x / 11) * 2 + 1 << endl;
    }else if( a == 0 ){
        cout << x / 11 * 2 << endl;
    }else{
        cout << (x / 11) * 2 + 2 << endl;
    }
    return 0;
}
