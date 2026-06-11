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
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c[] = {'S','W'};
    rep(i,2){
        rep(j,2){
            string t;
            t += c[i];
            t += c[j];
            for(int k = 1; k < n - 1; k++){
                if(t[k] == 'S'){
                    if(s[k] == 'o'){
                        t += t[k-1];
                    }else{
                        rep(_,2)if(t[k-1]!=c[_])t += c[_];
                    }
                }else{
                    if(s[k] != 'o'){
                        t += t[k-1];
                    }else{
                        rep(_,2)if(t[k-1]!=c[_])t += c[_];
                    }
                }
            }
            bool f = true;
            if(t[n-1] == 'S'){
                if(s[n-1] == 'o')f &= t[n-2] == t[0];
                else f &= t[n-2] != t[0];
            }else{
                if(s[n-1] != 'o')f &= t[n-2] == t[0];
                else f &= t[n-2] != t[0];
            }
            if(t[0] == 'S'){
                if(s[0] == 'o')f &= t[n-1] == t[1];
                else f &= t[n-1] != t[1];
            }else{
                if(s[0] != 'o')f &= t[n-1] == t[1];
                else f &= t[n-1] != t[1];
            }
            if(f){
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}