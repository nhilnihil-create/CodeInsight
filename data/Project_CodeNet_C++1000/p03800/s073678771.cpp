#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define RREP(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}


int main(){
    ll N; cin >> N; string s; cin >> s;
    
    REP(st, 2) REP(nx, 2){
        
        vb ans(N, false); ans[0] = st; ans[1] = nx; // true = sheep
        
        bool ok = true;
        FOR(i, 1, N+1){
            if(i == N-1 || i == N){
                ll nx = (i+1)%N, cur = i%N;
                if(ans[cur]){
                    if(s[cur] == 'o' && ans[nx] != ans[i-1]){
                        ok = false; break;
                    }
                    else if(s[cur] == 'x' && ans[nx] == ans[i-1]){
                        ok = false; break;
                    }
                }
                else{
                    if(s[cur] == 'x' && ans[nx] != ans[i-1]){
                        ok = false; break;
                    }
                    else if (s[cur] == 'o' && ans[nx] == ans[i-1]){
                        ok = false; break;
                    }
                }
            }
            else{
                if(ans[i]){ // sheep
                    if(s[i] == 'o') ans[i+1] = ans[i-1];
                    else ans[i+1] = 1-ans[i-1];
                }
                else{ // wolf
                    if(s[i] == 'x') ans[i+1] = ans[i-1];
                    else ans[i+1] = 1-ans[i-1];
                }
            }
        }
        if(ok){
            REP(i, N) cout << (ans[i] ? "S" : "W");
            cout << endl; return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
