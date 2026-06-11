#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

vector<vector<int>> G;

int solve(int u){
    int k = G[u].size();
    if(k == 0) return 0;
    vector<int> s(k);
    rep(i,k){
        s[i] = solve(G[u][i]);
    }
    sort(s.begin(),s.end());
    int res = 0;
    rep(i,k){
        res = max(res,s[i]+k-i);
    }
    return res;
}

int main(){
    int N; cin >> N;
    G.resize(N);
    repr(i,1,N){
        int a; cin >> a;
        a--;
        G[a].push_back(i);
    }
    int ans = solve(0);
    cout << ans << endl;

}

    

