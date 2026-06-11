#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main(){
    int N;
    cin >> N;
    vll T(N);
    cin >> T;
    sort(T.begin(),T.end());
    if(N == 1){
        cout << T[0] << endl;
        return 0;
    }
    ll ans = T[0] * (T[1]/__gcd(T[0],T[1]));
    for(int i=2; i<N; i++){
        if(ans < T[i]){
            ans = ans * (T[i]/__gcd(ans,T[i]));
        }else{
            ans = T[i] * (ans/__gcd(ans,T[i]));
        }
    }
    cout << ans << endl;
}