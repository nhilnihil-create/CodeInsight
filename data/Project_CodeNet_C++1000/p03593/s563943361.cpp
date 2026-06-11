/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
 
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

int main(void){
    int h, w;
    cin >> h >> w;
    string str = "";

    for(int i = 0; i < h; i++){
        string tmp;
        cin >> tmp;
        str += tmp;
    }

    map<char,int> mp;

    for(int i = 0; i < str.size(); i++){
        mp[str[i]]++;
    }

    int nec1;
    int nec2;
    int nec4;

  

    if(str.size() % 2 == 0){
        nec1 = 0;
    } else {
        nec1 = 1;
    }

    if(h % 2 != 0 && w % 2 != 0){
        nec2 = h / 2 + w / 2;
        nec4 = (h / 2) * (w / 2);
    } else {
        nec4 = (h / 2) * (w / 2);
        nec2 = (h % 2 == 0? h / 2 : w / 2);
    }

    if(w % 2 == 0 && h % 2 == 0){
        nec2 = 0;
        nec4 = (h / 2) * (w / 2);
    }

    for(int i = 0; i < nec1; i++){
        for(auto &i : mp){
            if(i.second % 4 == 1 || i.second % 4 == 3){
                i.second--;
                break;
            }
        }
    }

    int cnt = 0;

    for(int i = 0; i < nec2; i++){
        for(auto &i : mp){
            if(i.second % 4 == 2 && i.second >= 2){
                i.second -= 2;
                cnt++;
                break;
            }
        }
    }

    for(int i = 0; i < nec2 - cnt; i++){
        for(auto &i : mp){
            if(i.second % 2 == 0 && i.second >= 2){
                i.second -= 2;
                break;
            }
        }
    }

    for(int i = 0; i < nec4; i++){
        for(auto &i : mp){
            if(i.second % 4 == 0 && i.second >= 4){
                i.second -= 4;
                break;
            }
        }
    }

    bool ok = true;

    for(auto &i : mp){
        //cout << i.second << endl;
        if(i.second != 0){
            ok = false;
        }
    }

      //cout << nec1 << " " << nec2 << " " << nec4 << endl;

    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}