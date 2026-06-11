/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------

int main(void){
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    map<ll,ll> rem;
    map<ll,ll> mp;
    rep(i, n){
        rem[x[i] % m]++;
        mp[x[i]]++;
    }
    map<ll,map<ll,ll>> mp2;
    for(auto &i : mp){
        mp2[i.first % m][i.first] = i.second / 2;
    }

    ll ans = 0;
    ll M;
    if(m % 2 == 0){
        M = m / 2;
    } else {
        M = (m - 1) / 2;
    }
    for(int i = 0; i <= M; i++){
        if(i == 0){
            ans += rem[i] / 2;
        } else if(m % 2 == 0 && i == m / 2){
            ans += rem[i] / 2;
        } else {
            ans += min(rem[i], rem[m - i]);
            ll rest = abs(rem[i] - rem[m - i]);
            //cout << i << " " << rest << endl;
            ll plus = 0;
            if(rem[i] > rem[m - i]){
                ll totalpair = 0;
                for(auto &j : mp2[i]){
                    totalpair += j.second;
                }
                plus += min(totalpair, rest / 2);
            } else if(rem[i] <= rem[m - i]) {
                ll totalpair = 0;
                for(auto &j : mp2[m-i]){
                    totalpair += j.second;
                }
                plus += min(totalpair, rest / 2);
            }

            ans += plus;
        }
    }

    cout << ans << endl;


}
