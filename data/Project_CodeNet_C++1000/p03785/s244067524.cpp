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

int main()
{
    ll N,C,K;
    cin >> N >> C >> K;
    vll T(N);
    cin >> T;
    sort(T.begin(),T.end());
    ll ans = 0;
    int i=0;
    while(i<N){
        int j=i;
        for(;i<N && i<j+C && T[i]-T[j]<=K; i++);
        ans++;
    }
    cout << ans << endl;
}
