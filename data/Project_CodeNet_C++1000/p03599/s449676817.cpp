#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define IREP(i, v) for(auto i = (v).begin(); i != (v).end(); ++i)
#define IRREP(i, v) for(auto i = (v).rbegin(); i != (v).rend(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<decltype(v[0])>())
#define SZ(x) ((int)(x).size())
#define REV(x) reverse(ALL(x))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ld = long double;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using Pi_i = pair<int, int>;
using Pll_ll = pair<ll, ll>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;
using VULL = vector<ull>;

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const ll LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}


int main(){
    int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
    VB water(F+1, false), sugar(F+1, false);
    REPS(i, F/(100*A)){
        REPS(j, F/(100*B))
            if((i || j) && 100*(i*A + j*B) <= F)
                water[100*(i*A + j*B)] = true;
    }
    REPS(i, F/C){
        REPS(j, F/D){
            if(i*C + j*D <= F)
                sugar[i*C + j*D] = true;
        }
    }
    int ansM(100*A), ansS(0);
    ld c(0.0);
    FORS(i, 1, F){
        if(!water[i]) continue;
        REPS(j, F){
            if(!sugar[j]) continue;
            if(i+j > F) continue;
            if(100 * j > E * i) continue;
            ld p(i), q(j);
            ld tmp(100*q / (p+q));
            if(chmax(c, tmp)){
                ansM = i + j;
                ansS = j;
            }
        }
    }
   
    cout << ansM << " " << ansS << endl;
    return 0;
}
