#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

const ll mod = 1e9+7;

int main()
{
    int N,P;
    cin >> N >> P;
    int cnt=0;
    REP(i,N){
        int a;
        cin >> a;
        if(0 != a%2)cnt++;
    }
    ll ans=0;
    if(0 == cnt){
        ans = 1LL << N;
    }else{
        ans = 1LL << (N-1);
    }
    if(P){
        ans = (1LL << N) - ans;
    }
    cout << ans << endl;
}