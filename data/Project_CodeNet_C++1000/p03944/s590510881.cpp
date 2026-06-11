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
    ll W, H, N;
    cin >> W >> H >> N;

    ll t = H, b = 0, l = 0, r = W;
    ll x, y, a;
    rep(i, N){
        cin >> x >> y >> a;
        switch(a){
            case 1:
                l = max(l, x);
                break;
            case 2:
                r = min(r, x);
                break;
            case 3:
                b = max(b, y);
                break;
            case 4:
                t = min(t, y);
                break;
        }
    }

    if(t <= b || l >= r){
        cout << 0 << endl;
    }else{
        cout << (t - b) * (r - l) << endl;
    }

    return 0;
}
