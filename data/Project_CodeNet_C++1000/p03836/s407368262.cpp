#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{   
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans = "";
    int h = ty - sy;
    int w = tx - sx;

    // 1往復目
    for(int i=0; i<h; ++i) ans += "U";
    for(int i=0; i<w; ++i) ans += "R";
    for(int i=0; i<h; ++i) ans += "D";
    for(int i=0; i<w; ++i) ans += "L";
    // 2往復目
    ans += "L";
    for(int i=0; i<h+1; ++i) ans += "U";
    for(int i=0; i<w+1; ++i) ans += "R";
    ans += "D";
    ans += "R";
    for(int i=0; i<h+1; ++i) ans += "D";
    for(int i=0; i<w+1; ++i) ans += "L";
    ans += "U";

    cout << ans << endl;

    return 0;
}