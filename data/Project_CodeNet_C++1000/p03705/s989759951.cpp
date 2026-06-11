#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    ll N,A,B; cin >>N>>A>>B;
    ll ans=B*(N-1)+A-A*(N-1)-B+1;
    if ((N==1&&A!=B)||(A>B))ans=0;
    cout<<ans;
    return 0;
}