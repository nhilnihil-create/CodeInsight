#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
#ifdef DEBUG
template<typename T>
class Vec : public vector<T>{
public:
    Vec(){}
    Vec(int n):vector<T>(n){}
    Vec(int n, T a):vector<T>(n,a){}
    T& operator[](long long n){
        if(n < 0 or n >= this->size())throw out_of_range("Vec");
        return this->at(n);
    }
    const T& operator[](long long n)const{
        if(n < 0 or n >= this->size())throw out_of_range("Vec");
        return this->at(n);
    }
};
#define vector Vec
template<typename T>
ostream &operator<<(ostream &os, set<T> st) {
    for(auto x : st) cerr << x << ' ';
    return os;
}
template<typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> mp) {
    for(auto x : mp) cerr << x << ' ';
    return os;
}
#endif
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    map<int,vector<int>>mp;
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    vector<int>s(m+1);
    rep(i,n-1){
        mp[a[i+1]].push_back(i);
        if(a[i] < a[i+1]){
            s[a[i]+1]++;
            s[a[i+1]]--;
        }else if(a[i+1] < a[i]){
            s[a[i]+1]++;
            s[m]--;
            s[0]++;
            s[a[i+1]]--;
        }
    }
    rep(i,m)s[i+1] += s[i];
    ll ans = 0;
    rep(i,n-1){
        ans += min(a[i+1] + 1,(a[i+1]-a[i]+m)%m);
    }
    ll pre = ans;
    show(ans);
    for(int  x = 1; x < m; x++){
        ll temp = pre;
        for(int i : mp[x - 1]){
            temp += (a[i+1] - a[i] + m) % m - 1;
        }
        temp -= s[x - 1];
        ans = min(ans, temp);
        pre = temp;
    }
    cout << ans << endl;
}