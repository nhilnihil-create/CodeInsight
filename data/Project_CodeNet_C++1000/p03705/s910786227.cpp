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
    long n, a, b;
    cin >> n >> a >> b;
    if(a > b) cout << "0" << endl;
    else{
        long ans = (a+b*(n-1)) - (b+a*(n-1)) + 1;
        if(ans < 0) ans = 0;
        cout << ans << endl;
    }
    return 0;
}