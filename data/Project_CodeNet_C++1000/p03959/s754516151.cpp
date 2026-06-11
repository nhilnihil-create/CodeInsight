#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    int n;
    cin >> n;
    vector<lint> t(n + 2), a(n + 2);
    t[0] = 0;
    a[n + 1] = 0;
    REP(i, 1, n + 1){
        cin >> t[i];
    }
    REP(i, 1, n + 1){
        cin >> a[i];
    }
    lint ans = 1;
    REP(i, 1, n + 1){
        if(t[i - 1] < t[i] && a[i] > a[i + 1]){
            if(t[i] != a[i]){
                ans = 0;
            }
        }else if(t[i - 1] < t[i]){
            if(t[i] > a[i]){
                ans = 0;
            }
        }else if(a[i] > a[i + 1]){
            if(t[i] < a[i]){
                ans = 0;
            }
        }else{
            ans *= min(t[i], a[i]);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}