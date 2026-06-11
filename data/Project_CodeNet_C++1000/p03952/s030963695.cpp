#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>K;
    if(N == 2){
        cout<<(K == 2 ? "Yes\n1\n2\n3" : "No")<<endl;
    }else if(K == 1 || K == N*2 - 1){
        cout<<"No"<<endl;
    }else {
        cout<<"Yes"<<endl;
        vec ans(N*2 - 1);
        vector<bool> used(N*2, false);
        if(K == 2){
            ans[N - 1] = 2;
            ans[N - 2] = 1;
            ans[N - 3] = 4;
            ans[N] = 3;
            rep(i,4) used[i+1] = true;
        }else {
            ans[N - 1] = K;
            ans[N - 2] = K + 1;
            ans[N - 3] = K - 1;
            ans[N] = K - 2;
            reps(i, K - 3, K + 1) used.at(i + 1) = true;
        }
        ll id = 0;
        reps(i, 1, N * 2) {
            if (id == N - 3) id += 4;
            if (used[i]) i += 4;
            if(i == N * 2) break;
            //cout<<id<<' '<<i<<endl;
            ans.at(id++) = i;
        }
        rep(i, N * 2 - 1) cout<<ans[i]<<endl;

    }
}