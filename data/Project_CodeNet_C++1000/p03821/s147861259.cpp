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

int main()
{
    int N;
    cin >> N;
    vll A(N),B(N);
    REP(i,N){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for(int i=N-1; i>=0; i--){
        ll nA = A[i] + ans;
        ll cnt = nA/B[i];
        if(0 != nA%B[i]){
            cnt++;
        }
        ans += B[i]*cnt-nA;
    }
    cout << ans << endl;
}