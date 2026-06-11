#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long C(long n, long r){
    if(n < r) return 0;
    long p[n+1][n+1];
    p[0][0] = 1;
    for(int i = 1; i <= n; i++){
        p[i][0] = 1;
        p[i][i] = 1;
        for(int j = 1; j <= i-1; j++){
            p[i][j] = p[i-1][j] + p[i-1][j-1];
        }
    }
    return p[n][r];
}

void solve()
{
    int A, B;
    cin >> A >> B;
    if(A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
    return;
}

int main()
{
    solve();
    return 0;
}