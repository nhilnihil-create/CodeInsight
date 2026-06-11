#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18;
const int N = (int)1e5 + 100;
const int MAXA = (int)3e6;
int num[N];
bool have[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)num[i] = 1;
    have[1] = 1;
    for(int i = 1;i <= m;++i){
        int u,v;
        cin >> u >> v;
        num[u]--;
        num[v]++;
        if(have[u])have[v] = 1;
        if(!num[u])have[u] = 0;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)ans += have[i];
    cout << ans;
    return 0;
}
