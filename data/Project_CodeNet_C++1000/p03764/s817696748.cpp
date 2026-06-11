#include <bits/stdc++.h>
using namespace std;

long long n, m, x[100005], y[100005], sumx[100005], sumy[100005], start, ax, ay;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    cin >> start;
    for(int i=1; i<n; i++) {
        cin >> x[i];
        x[i] -= start;
        sumx[i] = sumx[i-1]+x[i];
    }
    cin >> start;
    for(int i=1; i<m; i++) {
        cin >> y[i];
        y[i] -= start;
        sumy[i] = sumy[i-1]+y[i];
    }

    for(int i=0; i<n; i++) {
        long long sob = sumx[n-1]-sumx[i], tob=n-i-1;
        ax = (ax+sob-tob*x[i])%MOD;
    }
    for(int i=0; i<m; i++) {
        long long sob = sumy[m-1]-sumy[i], tob=m-i-1;
        ay = (ay+sob-tob*y[i])%MOD;
    }
    cout << (ax*ay)%MOD << endl;

    return 0;
}