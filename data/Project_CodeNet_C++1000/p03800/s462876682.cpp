/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
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
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
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
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int n;
bool check(string ans, string &s, char last){
    for(int i = 1; i < n - 2; i++){
        if(s[i] == 'o'){
            if(ans[i] == 'S'){
                ans += ans[i - 1];
            } else {
                if(ans[i - 1] == 'S'){
                    ans += 'W';
                } else {
                    ans += 'S';
                }
            }
        } else {
            if(ans[i] == 'S'){
                if(ans[i - 1] == 'S'){
                    ans += 'W';
                } else {
                    ans += 'S';
                }
            } else {
                ans += ans[i - 1];
            }
        }
    }
    ans += last;
    //cout << ans << endl;
    bool res = true;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            if(ans[i] == 'S'){
                if(ans[(i==0?n-1:i - 1)] != ans[(i==n-1?0:i + 1)]){
                    res = false;
                }
            } else {
                if(ans[(i==0?n-1:i - 1)] == ans[(i==n-1?0:i + 1)]){
                    res = false;
                }
            }
        } else {
            if(ans[i] == 'S'){
                // if(i == n - 1){
                //     cout << ans[(i==0?n-1:i - 1)] << " " << ans[(i==n-1?0:i + 1)] << endl;
                // }
                if(ans[(i==0?n-1:i - 1)] == ans[(i==n-1?0:i + 1)]){
                    res = false;
                }
            } else {
                if(ans[(i==0?n-1:i - 1)] != ans[(i==n-1?0:i + 1)]){
                    res = false;
                }
            }
        }
    }
    if(res){
        cout << ans << endl;
    }
    return res;
}

int main(void){
    string s;
    cin >> n >> s;

    string ans = "";
    ans += 'S';
    char last;
    if(s[0] == 'o'){
        last = 'S';
        ans += 'S';
    } else {
        last = 'W';
        ans += 'S';
    }

    if(check(ans, s, last)) return 0;

    ans = "";
    ans += "S";
    if(s[0] == 'o'){
        last = 'W';
        ans += 'W';
    } else {
        last = 'S';
        ans += 'W';
    }

    if(check(ans, s, last)) return 0;

    ans = "";
    ans += "W";
    if(s[0] == 'o'){
        last = 'S';
        ans += 'W';
    } else {
        last = 'W';
        ans += 'W';
    }

    if(check(ans, s, last)) return 0;

    ans = "";
    ans += "W";
    if(s[0] == 'o'){
        last = 'W';
        ans += 'S';
    } else {
        last = 'S';
        ans += 'S';
    }

    if(check(ans, s, last)) return 0;

    cout << -1 << endl;

}