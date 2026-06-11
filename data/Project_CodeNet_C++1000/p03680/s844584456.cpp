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
    ll N;
    cin >> N;

    ll a[N + 1];
    REP(i, N){
        cin >> a[i];
    }

    ll lighted[N + 1];
    REP(i, N){
        if(i == 1){
            lighted[i] = 1;
        }else{
            lighted[i] = 0;
        }
    }

    ll p = a[1];
    ll ans = 1;
    bool success = false;
    while(lighted[p] != 1){
        if(p == 2){
            success = true;
            break;
        }
        lighted[p] = 1;
        p = a[p];
        ans++;
    }

    if(success){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}