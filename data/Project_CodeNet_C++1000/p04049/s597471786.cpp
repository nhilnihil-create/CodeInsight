#include <bits/stdc++.h>
#define ll long long
#define Nmax 2004
using namespace std;

int n,k,nrf[Nmax],DP[Nmax][Nmax],dif[Nmax][Nmax],a,b;
int ans = 1e9;
vector<int> v[Nmax];

void dfs(int nod, int ant){
    nrf[nod]++;
    for (int i=0;i<=k;i++) DP[nod][i] = 0;
    for (auto it : v[nod]){
        if (it == ant) continue;
        dfs(it, nod);
        nrf[nod] += nrf[it];
        for (int i=0;i<k;i++){
            DP[nod][i+1] += DP[it][i];
            if (i+i+1 > k){
                dif[nod][i+1] = min(dif[nod][i+1], -DP[it][k-i-1] + DP[it][i]);
            }
        }
    }
    DP[nod][0] = nrf[nod];
    for (int i=1;i<=k;i++){
        if (i+i-1<=k) continue;
        DP[nod][i] = DP[nod][k-i+1] + dif[nod][i];
    }
    if (nrf[nod]==1) DP[nod][1] = 0;
    for (int i=1;i<=k;i++) DP[nod][i] = min(DP[nod][i], DP[nod][i-1]);
    ans = min(ans, DP[nod][k] + n - nrf[nod]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    k++;
    memset(DP,0x3f,sizeof(DP));
    memset(dif,0x3f,sizeof(dif));
    for (int i=2;i<=n;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);

//    int ans = 1e9;
//    for (int i=0;i<=k;i++) ans = min(ans, DP[1][i]);
    cout << ans << '\n';

    return 0;
}
