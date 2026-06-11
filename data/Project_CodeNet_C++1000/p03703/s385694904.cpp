#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





















template <typename T>
class BIT {
private:
    int b;    // bit.size() < 2^n になる最小の2^n
    vector<T> bit;
    
public:
    BIT(int n) : bit(n + 1){
        b = 1;
        while(b <= n){
            b <<= 1;
        }
    }
    
    // posまでの合計
    T sum(int pos){
        T sum = 0;
    
        for(pos++; pos > 0; pos -= pos & -pos){
            sum += bit[pos];
        }
        
        return sum;
    }
    
    void add(int pos, T x){
        for(pos++; pos < bit.size(); pos += pos & -pos){
            bit[pos] += x;
        }
    }
    
    int lower_bound(T x){
        int res = 0;
    
        for(int i = b; i > 0; i >>= 1){
            if(res + i < bit.size() && bit[res + i] < x){
                x -= bit[res + i];
                res += i;
            }
        }
        
        return res;
    }
};


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    vector<ll> b(n + 1);
    REP(i, n){
        b[i + 1] = a[i] + b[i] - k;
    }
    vector<ll> t = b;
    sort(t.begin(), t.end());
    vector<ll> c(n + 1);
    REP(i, n + 1){
        ll l = 0, r = n + 1;
        while(r - l > 1){
            ll m = (l + r) / 2;
            ((t[m] <= b[i])? l : r) = m;
        }
        c[i] = l;
    }
    BIT<ll> bit(n + 1);
    ll ans = 0;
    REP(i, n + 1){
        ans += bit.sum(c[i]);
        bit.add(c[i], 1);
    }
    cout << ans << endl;
}