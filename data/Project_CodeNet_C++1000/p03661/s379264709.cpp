#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
ll N;
ll d[2000010];
/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>d[i];
    }

    REP(i,1,N){
        d[i] += d[i-1];
    }

    ll ans = LLINF;
    REP(i,0,N-1){
        ans = min(ans, abs(d[i] - (d[N-1] - d[i])));
    }

    cout<<ans<<endl;

    return 0;
}
