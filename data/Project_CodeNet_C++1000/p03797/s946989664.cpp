#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=(n); i--)
#define LREP(lst,itr) for(auto itr = lst.begin(); itr != lst.end(); ++itr)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define P(s) cout<<(s)<<endl
#define P2(a, b) cout<<(a)<<" "<<(b)<<endl
#define P3(a, b, c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define V2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

/*例: 数列Aで,整数x > Ai となるAiがK個となる最小の整数xを求めよ*/
ll N, M;

bool C(ll mid){//ここに条件を書く
    ll rest;
    rest = M - mid*2;

    // cout << mid << " " << rest << endl;
    if(rest < 0) return false;
    if((N+rest/2) < mid) return false;
    return true;
}

ll nibutan(ll lb, ll ub){
    while(ub-lb>1){
        // cout << lb<<" "<<ub <<endl;
        ll mid=(lb+ub)/2;
        if(C(mid)) lb=mid;
        else ub=mid;
    }
    return lb;
}

int main(){
    ll ans;
    cin >> N >> M;
    ans = nibutan(0, 1e12+2);
    P(ans);
}

// int main(){
//     ll N, M, ans=0, rest;
//     rest = M - 2*N;
//     if(rest>=0){

//     }else{

//     }
// }