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
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> v1(n), v2(n);
    REP(i, n){
        ll a;
        cin >> a;
        v1[i] = a;
        v2[i] = a;
    }

    ll res1 = 0, res2 = 0;
    REP(i, n-1){
        ll sum1 = v1[i] + v1[i+1];
        ll sumdif1 = sum1 - x;
        if(sumdif1 > 0){
            v1[i+1] -= sumdif1;
            if(v1[i+1] <0){
                v1[i] += v1[i+1];
                v1[i+1] = 0;
            }
            res1 += sumdif1;
        }  

        ll sum2 = v2[i] + v2[i+1];
        ll sumdif2 = sum2 - x;
        if(sumdif2 > 0){
            v2[i] -= sumdif2;
            if(v2[i] <0){
                v2[i+1] += v2[i];
                v2[i] = 0;
            }
            res2 += sumdif2;
        } 
    }
    cout << min(res1, res2) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}