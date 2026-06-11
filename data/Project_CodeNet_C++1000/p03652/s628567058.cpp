#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,m;
    cin >> n >> m;
    vector<queue<int>> v(n);
    REP(i,n){
        REP(j,m){
            int a;
            cin >> a;
            a--;
            v[i].emplace(a);
        }
    }
    int ans = INF;
    bool del[m] = {};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            while(del[v[j].front()]){
                v[j].pop();
            }
        }
        int cnt[m] = {};
        for(int j = 0; j < n; j++){
            cnt[v[j].front()]++;
        }
        int mx = 0, mx_itr;
        for(int j = 0; j < m; j++){
            if(cnt[j] > mx){
                mx = cnt[j];
                mx_itr = j;
            }
        }
        ans = min(ans, mx);
        del[mx_itr] = true;
    }
    cout << ans << endl;
    return 0;
}