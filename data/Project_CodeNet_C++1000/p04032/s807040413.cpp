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
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] == s[i + 1] ){
            cout << i + 1 << " " << i + 2;
            return 0;
        }
        if( i < s.length() - 1 && s[i] == s[i + 2] ){
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }
    cout << "-1 -1";
}
