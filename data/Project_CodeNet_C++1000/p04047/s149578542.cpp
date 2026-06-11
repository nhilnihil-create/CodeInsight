#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef long long ll;
typedef pair<int,int> pii;

const int M = 998244353 ;
const int MAX = (2e5) + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll x;
int n, ara[MAX];

int main() {
    ios::sync_with_stdio(false);
    //read;
    //write;

    cin >> n; n *= 2;
    FOR(i,0,n-1) {
        cin >> ara[i];
    }
    sort(ara, ara + n);
    for(int i = 0; i < n; i += 2) {
        x += ara[i];
    }
    cout << x << endl;
    return 0;
}

