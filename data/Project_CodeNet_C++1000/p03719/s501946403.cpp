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
    int a, b, c; cin >> a >> b >> c;
    if(a <= c && c <= b) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}