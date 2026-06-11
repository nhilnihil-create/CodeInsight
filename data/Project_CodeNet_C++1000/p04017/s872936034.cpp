#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, L, Q, ans=0, tmp=0;
vector<ll> A;
vector<vector<ll>> C;
string S;

signed main(){
    cin >> N;
    C.resize(20, vector<ll>(N, 0));
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    cin >> L >> Q;
    for(int i=1;i<N;i++) {
        ll id = lower_bound(A.begin(), A.end(), A[i]-L)-A.begin();
        C[0][i] = id;
    }
    for(int i=1;i<20;i++) {
        for(int j=1;j<N;j++) {
            C[i][j] = C[i-1][C[i-1][j]];
        }
    }
    for(int i=0;i<Q;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ans = 0;
        if(a>b) swap(a, b);
        for(int j=19;j>=0;j--) {
            if(C[j][b]>a) {
                b = C[j][b];
                ans += pow(2, j);
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}