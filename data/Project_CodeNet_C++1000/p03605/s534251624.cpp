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
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    if( a % 10 == 9 || a / 10 == 9 ) cout << "Yes";
    else cout << "No";
}


