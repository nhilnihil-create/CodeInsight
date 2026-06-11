#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>
#include <unordered_map>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define all(s) s.begin(), s.end()
#define fo(i, start, finish) for(int i = start; i <= finish; i ++)
#define y1 kdfjsalsdkf

const long long MXN = 1e5 + 10;
const long long MNN = 5e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, b[MXN], mx;
int used[MXN];

int main(){
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        mx = max(b[i], mx);
    }
    if(mx % 2 == 0){
        for(int i = 1; i <= n; i++){
            if(b[i] < mx / 2){
                cout << "Impossible";
                return 0;
            }
            used[b[i]]++;
        }
        if(used[mx / 2] != 1) return cout << "Impossible", 0;
        for(int i = mx; i > mx / 2; i--){
            if(used[i] < 2) return cout << "Impossible", 0;
        }
        cout << "Possible";
    } else {
        for(int i = 1; i <= n; i++){
            if(b[i] < (mx + 1) / 2){
                cout << "Impossible";
                return 0;
            }
            used[b[i]]++;
        }
        if(used[(mx + 1) / 2] != 2) return cout << "Impossible", 0;
        for(int i = mx; i > (mx + 1) / 2; i--){
            if(used[i] < 2) return cout << "Impossible", 0;
        }
        cout << "Possible";
    }
    return 0;
}

