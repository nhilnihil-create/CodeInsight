#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
bool pos[N];
int cnt[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    fill(cnt+1, cnt+n+1, 1);
    pos[1] = true;

    for (int i=1; i<=m; i++) {
        int x, y;
        cin>>x>>y;

        if (pos[x]) pos[y] = 1;
        cnt[x]--; cnt[y]++;
        if (cnt[x] == 0)    pos[x] = false;
    }

    int ans = 0;
    for (int i=1; i<=n; i++)    ans += pos[i];

    cout<<ans<<endl;
}
