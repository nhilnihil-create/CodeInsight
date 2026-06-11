#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, bool>> t(n);
    for(int i = 0; i < n; i++){
        if(i == 0)t[i].second = true;
        else t[i].second = false;
        t[i].first = 1;
    }
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        if(t[a].first >= 2){
            if(t[a].second){
                t[b].second = true;
            }
        }
        else{
            if(t[a].second){
                t[b].second = true;
            }
            t[a].second = false;
        }
        t[a].first -= 1;
        t[b].first += 1;
    }
    int ans = 0;
    for(auto p : t){
        if(p.second)ans++;
    }
    cout << ans << endl;
    system("pause");
}