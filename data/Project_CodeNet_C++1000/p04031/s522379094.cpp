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

    ll sum = 0;
    ll a[N];
    rep(i, N){
        cin >> a[i];
        sum += a[i];
    }

    ll cost1 = 0;
    ll cost2 = 0;
    ll center1 = sum / N;
    ll center2 = sum / N + 1;
    rep(i, N){
        cost1 += (center1 - a[i]) * (center1 - a[i]);
        cost2 += (center2 - a[i]) * (center2 - a[i]);
    }
    
    cout << min(cost1, cost2) << endl;

    return 0;
}