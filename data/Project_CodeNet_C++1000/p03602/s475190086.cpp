#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 311;
ll a[maxi][maxi];
string s;

ll warshall(int n) {
    ll ret = 0;

    for(int u = 1; u <= n; u++) {
        for(int v = u+1; v <= n; v++) {
            bool lol = true;
            for(int k = 1; k <= n; k++) {
                if(k == u || k == v) continue;
                if(a[u][v] > a[u][k] + a[k][v]) return -1;
                else if(a[u][v] == a[u][k] + a[k][v]) lol = false;
            }
            if(lol) ret += a[u][v];
        }
    }

    return ret;
}

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin>>a[i][j];
    }

    cout<<warshall(n)<<endl;
    return 0;
}
