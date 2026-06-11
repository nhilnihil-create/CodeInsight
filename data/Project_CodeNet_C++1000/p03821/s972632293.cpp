#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    ll N ;
    cin >> N ;

    ll A[N],B[N];

    rep(i,0,N) {
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for (int i=N-1; i>=0; i--) {
        A[i] += ans;
        if (A[i]%B[i]==0) {
            continue;
        }
        else {
            ll tmp;
            tmp = (A[i]/B[i]+1)*B[i]-A[i];
            A[i] += tmp;
            ans += tmp;
        }
    }

    cout << ans << endl;
}






