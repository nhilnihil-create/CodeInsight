#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M=510;
int sg[M][M];
int SG(int x, int y) {
    if (!x&&!y) return sg[x][y]=0;
    if (sg[x][y]!=-1) return sg[x][y];
    set<int> vis;
    for (int i=1; i*2<=x; i++) {
        vis.insert(SG(x-2*i, y+i));
    }
    for (int i=1; i*2<=y; i++) {
        vis.insert(SG(x+i, y-2*i));
    }
    for (int i=0; ; i++) if (!vis.count(i)) return sg[x][y]=i;
}
int main()
{

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#else
#endif // LOCAL
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    memset(sg, -1, sizeof(sg));
//    for (int i=0; i<10; i++) {
//        for (int j=0; j<10; j++) {
//            memset(sg, -1, sizeof(sg));
//            cout << SG(i, j) << " ";
//        }
//        cout << endl;
//    }
    ll n, m;
    cin >> n >> m;
    if (abs(n-m)<=1) cout << "Brown";
    else cout << "Alice";

    return 0;
}
