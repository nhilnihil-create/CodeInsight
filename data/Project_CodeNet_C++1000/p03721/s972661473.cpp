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
    ll N, K;
    cin >> N >> K;

    vector<pair<ll, ll> > v;
    ll a, b;
    rep(i, N){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    
    ll p = 0;
    ll vp = -1;
    while(p < K){
        vp++;
        p += v[vp].second;//cout << "p: " << p << ", vp: " << vp << endl;
    }

    cout << v[vp].first << endl;

    return 0;
}