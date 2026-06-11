#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    long long w, h, mn = 1e9, mx = 0;
    cin >> w >> h;
    if(!(w % 3) ||  !(h % 3)){
        cout << 0;
        return 0;
    }
    long long r = w / 3, l = h / 3;
    long long k = h / 2, m = w / 2;
    if(h % 2 == 1) k = r + (h + 1) / 2;
    if(w % 2 == 1) m = l + (w + 1) / 2;
    cout << min(h, min(w, min(k, m)));
}
