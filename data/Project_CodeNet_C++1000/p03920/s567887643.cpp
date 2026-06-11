#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)
#define pb push_back
#define INF 1000000007LL
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int,int> p;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int N;

ll f(ll x) {
    return x * (x+1) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    int cur = -1;
    FOR(i,1,N+1) {
        if (f(i-1) < N && N <= f(i) ) {
            cur = i;
            break;
        }
    }
    ll skip = f(cur) - N;
    REP(i,cur) {
        if(i+1==skip) continue;
        cout << i+1 << endl;
    }
    return 0;
}