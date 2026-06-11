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
typedef double d;
typedef int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a , b;
    cin >> a >> b;
    int c , d;
    if ( a == 'D' ) c = -1;
    else c = 1;
    if ( b == 'D' ) d = -1;
    else d = 1;
    if ( c * d == 1 ) cout << 'H';
    else cout << 'D';
}