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
    int b[26] = {0};
    for(int i = 0 ; i < s.length() ; i++) {
        int a = s[i] - 'a';
        b[a] = 1;
    }
    for( char i = 'a' ; i <= 'z' ; i++ ) {
        if ( b[i - 'a'] == 0 ) {
            cout << i;
            return 0;
        }
    }
    cout << "None";
}


