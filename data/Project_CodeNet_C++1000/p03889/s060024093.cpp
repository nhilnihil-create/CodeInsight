#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    string mirror(128, ' ');
    mirror['b'] = 'd';
    mirror['d'] = 'b';
    mirror['p'] = 'q';
    mirror['q'] = 'p';

    string s;
    cin >> s;
    int n = s.size();

    bool ok = true;
    for(int i=0; i<n; ++i){
        if(mirror[s[i]] != s[n-1-i])
            ok = false;
    }
    if(ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
