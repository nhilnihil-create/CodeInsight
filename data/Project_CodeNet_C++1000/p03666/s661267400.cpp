#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM + 7
#define MAX 10100000
#define INF 1e15
#define MAP 110
#define initial_value -1
#define LINF 1LL << 60
#define Pair pair<int, int>
#define chmax(a, b) (a < b ? a = b : 0)
#define chmin(a, b) (a > b ? a = b : 0)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
ll N,A,B,C,D;
int main(){
    cin >> N >> A >> B >> C >> D;
    ll diff = B-A;
    bool ans = false;
    for(ll i = 0; i < N; i++){
        ll ma = i*D - (N-i-1)*C;
        ll mi = i*C - (N-1-i)*D;
        if(mi <= diff && diff <= ma) ans = true;
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
