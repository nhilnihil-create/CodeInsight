#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long a, b, c;
    cin >> a >> b >> c;
    long ab = a*b, bc = b*c, ca = c*a;
    if(a%2 == 1 && b%2 == 1 & c%2 == 1){
        long ans = min(min(ab, bc), ca);
        cout << ans << endl;
    }else{
        cout << "0" << endl;
    }
    return 0;
}