#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
const int INF = 10000000;

int main(){
    int a, b, c; cin >> a >> b;
    c = a + b;

    if(a % 3 == 0){
        cout << "Possible" << endl;
        return 0;
    }else if(b % 3 == 0){
        cout << "Possible" << endl;
        return 0;
    }else if((a + b) % 3 == 0){
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}
