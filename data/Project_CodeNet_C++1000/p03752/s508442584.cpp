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
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    int N,K;
    cin >> N >> K;
    vll A(N);
    cin >> A;
    ll ans = 1LL << 60;
    for(int bit=0; bit<(1<<N); bit++){
        vint idxs;
        ll cost = 0;
        for(int i=0; i<N; i++){
            if(bit&(1<<i)){
                idxs.pb(i);
            }
        }
        if(idxs.size() < K)continue;
        ll hmax=A[0];
        int idx=0;
        REP(i,idxs.size()){
            for(int j=idx; j<idxs[i]; j++){
                if(A[j] > hmax){
                    hmax = A[j];
                }
            }
            if(0 == i){
                if(hmax >= A[idxs[i]]){
                    cost += hmax - A[idxs[i]];
                }
            }else{
                if(hmax >= A[idxs[i]]){
                    cost += hmax - A[idxs[i]] + 1;
                    hmax++;
                }else{
                    hmax = A[idxs[i]];
                }
            }
            idx = idxs[i]+1;
        }
        ans = min(ans,cost);
    }
    cout << ans << endl;
}