#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 100000

int n;
vector<int> G[MAX_N];

int dfs(int now){
    if(G[now].size() == 0) return 0;
    map<int, int> cnt;
    REP(i,G[now].size()){
        cnt[dfs(G[now][i]) + 1]++;
    }
    int res = 0;
    for(auto i : cnt){
        if(i.second == 0) continue;
        cnt[i.first + 1] += i.second - 1;
        res = i.first;
    }
    return res;
}

signed main(){
    cin >> n;
    int a;
    REP(i,n - 1){
        cin >> a;
        a--;
        G[a].emplace_back(i + 1);
    }
    cout << dfs(0) << endl;
    return 0;
}