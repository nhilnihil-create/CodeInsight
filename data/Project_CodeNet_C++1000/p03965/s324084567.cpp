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
    string s;
    cin >> s;
    int x = 0;
    for(int i = 0 ; i < s.length() ; i++ ) {
        if( s[i] == 'g' ) x++;
        else x--;
    }
    cout << x / 2;
}

