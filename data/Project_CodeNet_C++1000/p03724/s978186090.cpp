#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;
int deg[maxn];

int n, m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(deg[i] & 1)
            flag = false;
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
