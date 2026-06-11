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

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int A[100010];
    rep(i, N) cin >> A[i];
    int G = 0;
    rep(i, N) G = gcd(G, A[i]);
    int maximam = 0;
    rep(i, N) maximam = max(maximam, A[i]);
    if(K % G == 0 && K <= maximam) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
