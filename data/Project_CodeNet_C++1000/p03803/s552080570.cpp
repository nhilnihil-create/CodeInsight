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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b;
    cin >> a >> b;
    if ( a == 1 ) a = 14;
    if ( b == 1 ) b = 14;
    if ( a > b ) cout << "Alice";
    else if ( a == b ) cout << "Draw";
    else cout << "Bob";
}