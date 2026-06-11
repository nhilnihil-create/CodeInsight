#include<bits/stdc++.h>
using namespace std;
const int N = 205;
const int maxS = 40005;
long long f[2][2*maxS],n,m,a[N];
const long long MOD =1e17+7;
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
             f[1][j] = ((f[1][j]%MOD) + (f[0][j]%MOD))%MOD;
             if (j+a[i] < 2*maxS) f[1][j+a[i]] = ((f[1][j+a[i]]%MOD) + (f[0][j]%MOD))%MOD;
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
        nhap();
        xuli();

}
