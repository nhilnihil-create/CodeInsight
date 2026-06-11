#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    cout << string(tx - sx, 'R');
    cout << string(ty - sy, 'U');
    cout << string(tx - sx, 'L');
    cout << string(ty - sy, 'D');
    
    cout << "D";
    sy--, tx++;
    cout << string(tx - sx, 'R');
    cout << string(ty - sy, 'U');
    cout << "L";

    cout << "U";
    sy++, tx--;
    sx--, ty++;
    cout << string(tx - sx, 'L');
    cout << string(ty - sy, 'D');
    cout << "R";
    cout << endl;
}
