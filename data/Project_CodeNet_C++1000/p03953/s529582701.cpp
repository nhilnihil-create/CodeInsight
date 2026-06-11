#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 998244353;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repr(i, n) for(int i = int(n) - 1; i >= 0; i--)
const int inf9 = 1e9; const lint inf18 = 1e18;
inline void YES(bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
inline void Yes(bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
inline void assert_NO(bool condition){ if(!condition){ cout << "NO" << endl; exit(0); } }
inline void assert_No(bool condition){ if(!condition){ cout << "No" << endl; exit(0); } }
inline void assert_minus_1(bool condition){ if(!condition){ cout << -1 << endl; exit(0); } }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(b) return gcd(b, a % b); else return a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint P(int n, int r){ if(r < 0 || n < r) return 0; return (fact[n] * inv[n - r] % mod); } lint C(int p, int q){ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }
template<class itr, class itr2> bool next_sequence2(itr first, itr last, itr2 first2, itr2 last2){ itr now = last; itr2 now2 = last2; while(now != first){ now--, now2--; (*now)++; if((*now) == (*now2)){ (*now) = 0; }else{ return true; } } return false; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int at(lint i, int j){ return (i >> j) & 1; }
random_device rnd;
bool is_in_board(lint y, lint x, lint H, lint W){ return (0 <= y && y < H && 0 <= x && x < W); }

int main(){
    int N;
    cin >> N;
    lint x[N];
    cins(x, x + N);
    lint diff[N - 1];
    rep(i, N - 1){
        diff[i] = x[i + 1] - x[i];
    }
    int M;
    lint K;
    cin >> M >> K;
    vector<int> arr(N - 1);
    iota(all(arr), 0);
    rep(i, M){
        int a;
        cin >> a;
        a -= 2;
        swap(arr[a], arr[a + 1]);
    }
    vector<vector<int>> move(60, vector<int>(N - 1));
    move[0] = arr;
    rep(i, 59){
        rep(j, N - 1){
            move[i + 1][j] = move[i][move[i][j]];
        }
    }
    rep(i, N - 1){
        arr[i] = i;
        rep(j, 60){
            if(at(K, j)){
                arr[i] = move[j][arr[i]];
            }
        }
    }
    lint now = x[0];
    cout << now << endl;
    rep(i, N - 1){
        now += diff[arr[i]];
        cout << now << endl;
    }
}
