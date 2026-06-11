#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    pair<ll, int> a[n];
    REP(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int ans = 0;
    REP(i,n){
        if(i % 2 != a[i].second % 2) ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}