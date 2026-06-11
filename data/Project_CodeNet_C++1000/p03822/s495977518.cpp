#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> G[100100];

int dfs(int v){
    map<int, int> rets;
    for(auto&& next : G[v]){
        int ret = dfs(next);
        rets[ret]++;
    }

    int val = 0;
    for(auto&& p : rets){
        int r = p.first;
        int n = p.second;
        if(val < r+1) val = r+n;
        else{
            val += n;
        }
    }

    return val;
}

int main(){
    int N;
    cin >> N;
    REP(i,N-1){
        int a;
        cin >> a;
        a--;
        G[a].push_back(i+1);
    }

    int ans = dfs(0);

    cout << ans << endl;
    return 0;
}
