#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    LL sx;
    LL sy;
    LL tx;
    LL ty;

    cin >> sx >> sy >> tx >> ty;

    LL diff_x=tx-sx;
    LL diff_y=ty-sy;

    for(LL i=0; i<diff_x; i++){
        cout << 'R';
    }
    for(LL j=0; j<diff_y; j++){
        cout << 'U';
    }
    for(LL i=0; i<diff_x; i++){
        cout << 'L';
    }
    for(LL j=0; j<diff_y; j++){
        cout << 'D';
    }
    cout << 'D';
    for(LL i=0; i<=diff_x; i++){
        cout << 'R';
    }
    for(LL j=0; j<=diff_y; j++){
        cout << 'U';
    }
    cout << 'L';
    cout << 'U';
    for(LL i=0; i<=diff_x; i++){
        cout << 'L';
    }
    for(LL j=0; j<=diff_y; j++){
        cout << 'D';
    }
    cout << 'R';
    cout << endl;

    return 0;
}
