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
    ll A, B, C;
    cin >> A >> B >> C;

    ll able[B];
    rep(i, B){
        able[i] = 0;
    }

    ll rBase = A % B;
    ll r = rBase;
    ll ans = 0;
    while(able[r] != 1){
        able[r] = 1;
        if(r == C){
            ans = 1;
            break;
        }
        r += rBase;
        r %= B;
    }

    if(ans == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}