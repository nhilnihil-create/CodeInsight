#include<bits/stdc++.h>
using namespace std;
const int N = 205;
const int maxS = 40005;
long long f[2][2*maxS],n,m,a[N];
const int MOD =1e9+7;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void nhap()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] -= m;
    }
}
void xuli()
{
    memset(f,0,sizeof(f));
    f[0][maxS] = 1;
    for (int i = 1; i<=n; i++) {
        for (int j = 0; j<2*maxS; j++) {
             f[1][j] = f[1][j] + f[0][j];
             f[1][j+a[i]] = f[1][j+a[i]] + f[0][j];
        }
        for (int j = 0; j<2*maxS; j++) {
            f[0][j] = f[1][j];
            f[1][j] = 0;
        }
    }
    cout << f[0][maxS] - 1  << '\n';
}
int main()
{
    init();
        nhap();
        xuli();

}
