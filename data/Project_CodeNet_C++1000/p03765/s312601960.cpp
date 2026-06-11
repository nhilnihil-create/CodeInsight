#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int sum[2][100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    rep(i, S.length()) {
        if(S[i] == 'A') sum[0][i + 1] += sum[0][i] + 1;
        else sum[0][i + 1] += sum[0][i] + 2;
    }
    rep(i, T.length()) {
        if(T[i] == 'A') sum[1][i + 1] += sum[1][i] + 1;
        else sum[1][i + 1] += sum[1][i] + 2;
    }
    int q; cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //cout << "*" << sum[0][b] - sum[0][a - 1] << " " << sum[1][d] - sum[1][c - 1] << " " << sum[0][b] - sum[0][a - 1] << " " << (sum[1][d] - sum[1][c - 1] - (sum[0][b] - sum[0][a - 1]) + 600000) % 3 << endl;
        int diff = (sum[1][d] - sum[1][c - 1] - (sum[0][b] - sum[0][a - 1]) + 600000) % 3;
        if(diff == 0) {
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
