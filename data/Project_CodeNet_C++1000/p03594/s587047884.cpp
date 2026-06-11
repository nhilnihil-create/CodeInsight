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

const string color = "RYGB";

int main()
{
    int h, w, d;
    cin >> h >> w >> d;

    vector<string> s(h, string(w, ' '));
    for(int y=0; y<h; ++y){
        for(int x=0; x<w; ++x){
            int y2 = y + x;
            int x2 = y + (w - x);
            int i = y2 / d % 2;
            int j = x2 / d % 2;
            s[y][x] = color[i*2+j];
        }
    }
    for(int i=0; i<h; ++i)
        cout << s[i] << endl;

    return 0;
}
