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
    if(m == 1){
        cout << n / 2 << endl;
        return 0;
    }
    vector<int>a(n);
    vector<vector<int>>b(m);
    rep(i,n){
        cin >> a[i];
        b[a[i]%m].push_back(a[i]);
    }
    rep(i,m)sort(b[i].begin(), b[i].end());
    int ans = 0;
    for(int i = 1; i < m / 2; i++){
        int s = (int) min(b[i].size(), b[m-i].size());
        ans += s;
        if(b[i].size() < b[m-i].size())swap(b[i], b[m-i]);
        int t =(int) b[i].size();
        for(int j = 0; j < (int)b[i].size() - 1; j++){
            show(b[i].size());
            if(b[i][j] == b[i][j+1]){
                if(t - 2 >= s){
                    ans++;
                    j++;
                    t-=2;
                }
            }
        }
        show(ans);
    }
    if(m % 2 == 0){
        ans += b[m / 2].size() / 2;
    }else{
        int i = m / 2;
        int s = (int) min(b[i].size(), b[m-i].size());
        ans += s;
        if(b[i].size() < b[m-i].size())swap(b[i], b[m-i]);
        int t =(int) b[i].size();
        for(int j = 0; j < (int)b[i].size() - 1; j++){
            if(b[i][j] == b[i][j+1]){
                if(t - 2 >= s){
                    ans++;
                    j++;
                    t-=2;
                }
            }
        }
    }
    ans += b[0].size() / 2;
    cout << ans << endl;
}