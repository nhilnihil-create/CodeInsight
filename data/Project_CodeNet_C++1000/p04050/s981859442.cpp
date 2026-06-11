#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int N, M, A[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vi odd, even;
    rep(i, M) {
        cin >> A[i];
        (A[i] & 1 ? odd : even).push_back(A[i]);
    }

    if(sz(odd) > 2) {
        cout << "Impossible" << endl;
        return 0;
    }

    vi a, b;
    if(sz(odd))a.push_back(odd[0]);
    each(e, even)a.push_back(e);
    if(sz(odd) == 2)a.push_back(odd[1]);
    if(a[0] - 1 > 0)b.push_back(a[0] - 1);
    FOR(i, 1, sz(a) - 1)b.push_back(a[i]);
    b.push_back(N - accumulate(all(b), 0));
    rep(i, M)cout << a[i] << (i != M - 1 ? ' ' : '\n');
    cout << sz(b) << endl;
    rep(i, sz(b))cout << b[i] << (i != sz(b) - 1 ? ' ' : '\n');
}