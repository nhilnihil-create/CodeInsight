#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;


int main(){
    ll x, y; cin >> x >> y;
    if(-1 <= x - y &&  x - y <= 1){
        cout << "Brown" << endl;
    }
    else{
        cout << "Alice" << endl;
    }


    return 0;
}