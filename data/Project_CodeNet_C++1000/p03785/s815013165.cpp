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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C, K;
    cin >> N >> C >> K;
    int T[100010];
    rep(i, N) cin >> T[i];
    sort(T, T + N);
    int ans = 0;
    int a = 0, b = 0;
    while(a < N) {
        while(b + 1 < N && b + 1 - a  < C && T[b + 1] <= T[a] + K) {b++;}
        ans++;
        //cout << a << " " << b << " " << endl;
        a = b + 1;
        
    }
    cout << ans << endl;

    return 0;
}
