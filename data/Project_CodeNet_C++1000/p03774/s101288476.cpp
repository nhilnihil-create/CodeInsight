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
    ll N, M;
    cin >> N >> M;

    ll a[N + 1], b[N + 1];
    ll c[M + 1], d[M + 1];
    REP(i, N){
        cin >> a[i] >> b[i];
    }
    REP(i, M){
        cin >> c[i] >> d[i];
    }

    ll dist;
    ll closest;
    REP(i, N){
        dist = 500000000;
        closest = 0;
        REP(j, M){
            if(dist > abs(c[j] - a[i]) + abs(d[j] - b[i])){
                dist = abs(c[j] - a[i]) + abs(d[j] - b[i]);
                closest = j;
            }
        }
        cout << closest << endl;
    }

    return 0;
}