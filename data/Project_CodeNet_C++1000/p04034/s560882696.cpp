#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n,1);
    vector<bool> b(n,false);
    b[0]=true;
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        a[x-1]--;
        a[y-1]++;
        if(b[x-1]==true) b[y-1]=true;
        if(a[x-1]==0) b[x-1]=false;
    }

    int ans=0;
    for(int i = 0; i < n; i++) {
        if(b[i]==true) ans++;
    }
    cout << ans << endl;

    return 0;
}