#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll ls = 0, rs = 0;
    REP(i, s.size()){
        if(s[i] == '(') ls++;
        if(s[i] == ')') rs++;
    }
    deque<char> deq;
    REP(i, s.size()){
        if(s[i] == '(') deq.pb(s[i]);
        if(s[i] == ')'){
            if(!deq.empty()){
                if(deq.back() == '('){
                    deq.pop_back();
                    ls--; rs--;
                }
                else deq.push_back(')');
            }
            else deq.push_back(')');
        }
    }
    //cout << ls << ' ' << rs << endl;
    REP(i, ls){
        s = s + ')';
    }
    REP(i, rs){
        s = '(' + s;
    }
    cout << s << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}