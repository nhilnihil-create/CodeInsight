#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




int main() {
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    REP(i, t.size()){
        if(t[i] == 'b')t[i] = 'd';
        else if(t[i] == 'd')t[i] = 'b';
        else if(t[i] == 'p')t[i] = 'q';
        else if(t[i] == 'q')t[i] = 'p';
    }
    cout << ((s == t)? "Yes" : "No") << endl;
}
