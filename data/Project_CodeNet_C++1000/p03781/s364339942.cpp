#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int x; cin >> x;
    REP(i, 1000000){
        if(i * (i+1) / 2 >= x){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}