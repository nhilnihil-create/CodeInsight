#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> box(n, 1);
    vector<bool> red(n, false);
    red[0] = true;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        box[a]--;
        box[b]++;
        if(red[a]) red[b] = true;
        if(box[a] == 0) red[a] = false;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(red[i]) ans++;
    }
    cout << ans << endl;
}
