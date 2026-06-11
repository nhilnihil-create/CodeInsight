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
    int x , a , b;
    cin >> x >> a >> b;
    if ( a >= b ) cout << "delicious";
    else if ( a + x >= b ) cout << "safe";
    else cout << "dangerous";
}
