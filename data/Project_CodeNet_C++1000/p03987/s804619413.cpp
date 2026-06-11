#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <istream>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <time.h>
#include <chrono>
#include <cstdio>
#include <fstream>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin() , x.end()
#define deb(z) cout << #z << ' ' << z << '\n';
#define pb push_back
const ll N = 2e5 + 4;
ll mn[4 * N] , mx[4 * N];
void upd1(ll v , ll l , ll r , ll i , ll x) {
    if(l + 1 == r) {
        mx[v] = x;
        return;
    }
    ll m = (r + l) / 2;
    if(m > i) {
        upd1(2 * v + 1 , l , m , i , x);
    } else {
        upd1(2 * v + 2 , m , r , i , x);
    }
    mx[v] = max(mx[2 * v + 1] , mx[2 * v + 2]);
}
void upd2(ll v , ll l , ll r , ll i , ll x) {
    if(l + 1 == r) {
        mn[v] = x;
        return;
    }
    ll m = (r + l) / 2;
    if(m > i) {
        upd2(2 * v + 1 , l , m , i , x);
    } else {
        upd2(2 * v + 2 , m , r , i , x);
    }
    mn[v] = min(mn[2 * v + 1] , mn[2 * v + 2]);
}
ll gmx(ll v , ll l , ll r , ll L , ll R) {
    if(l >= L && r <= R) {
        return mx[v];
    }
    if(l >= R || r <= L) {
        return 0;
    }
    ll m = (r + l) / 2;
    return max(gmx(2 * v + 1 , l , m , L , R) , gmx(2 * v + 2 , m , r , L , R));
}
ll gmn(ll v , ll l , ll r , ll L , ll R) {
    if(l >= L && r <= R) {
        return mn[v];
    }
    if(l >= R || r <= L) {
        return 1e9;
    }
    ll m = (r + l) / 2;
    return min(gmn(2 * v + 1 , l , m , L , R) , gmn(2 * v + 2 , m , r , L , R));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("test.txt" , "r" , stdin);
    //freopen("jump.out" , "w" , stdout);
    ll n;
    cin >> n;
    vector <ll> p(n);
    for(auto &x : p) {
        cin >> x;
    }
    p.insert(p.begin() , 0);
    p.push_back(0);
    for(int i = 0; i < 4 * N; i++) {
        mx[i] = 0;
        mn[i] = 1e9;
    }
    upd1(0 , 0 , N , 0 , 0);
    upd2(0 , 0 , N , 0 , p.size() - 1);
    vector <ll> left(p.size()) , right(p.size());
    for(int i = 1; i + 1 < p.size(); i++) {
        left[i] = i - gmx(0 , 0 , N , 0 , p[i]);
        upd1(0 , 0 , N , p[i] , i);
    }
    for(int i = p.size() - 2; i >= 1; i--) {
        right[i] = gmn(0 , 0 , N , 0 , p[i]) - i;
        upd2(0 , 0 , N , p[i] , i);
    }
    ll answer = 0;
    for(int i = 1; i + 1 < p.size(); i++) {
        //cout << left[i] << ' ' << right[i] << '\n';
        answer += left[i] * right[i] * p[i];
    }
    cout << answer;
    return 0;
}