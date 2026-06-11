#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll z;
    cin >> z;

    ll ans = (z / 11) * 2;
    if(z % 11 > 0 && z % 11 <= 6){
        ans += 1;
    }else if(z % 11 > 6){
        ans += 2;
    }

    cout << ans << endl;

    return 0;
}