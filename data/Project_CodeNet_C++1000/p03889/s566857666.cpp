#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#define itn int
#define scnaf scanf
#define pritnf printf
using namespace std;
typedef long long LL;
typedef long double LD;
int main () {
    string s;
    cin >> s;
    string t = s;
    reverse (t.begin (), t.end ());
    for (string::iterator it = t.begin (); it != t.end (); ++it) {
        switch (*it) {
            case 'b':
                *it = 'd';
                break;
            case 'd':
                *it = 'b';
                break;
            case 'p':
                *it = 'q';
                break;
            case 'q':
                *it = 'p';
                break;
        }
    }
    if (s == t) {
        printf ("Yes");
    }
    else {
        printf ("No");
    }
    return 0;
}
