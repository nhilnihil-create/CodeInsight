#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
signed main(void)
{
    int K;
    cin >> K;
    cout << "50" << endl;
    for (int i = 0; i < 50; i++){
        cout << i + (i + K) / 50 << " ";
    }
    return 0;
}