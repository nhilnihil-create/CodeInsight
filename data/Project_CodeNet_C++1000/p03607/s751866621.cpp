#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , a;
    cin >> n;
    set < int > s;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a;
        if ( s.count(a) == 1 ) s.erase(a);
        else s.insert(a);
    }
    cout << s.size();
}




