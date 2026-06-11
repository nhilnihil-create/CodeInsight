#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<(int)(b);++(i))
#define RREP(i,a,b) for(int (i)=(a);(i)>=(int)(b);--(i))
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int Maxn = 100010;

bool fix[Maxn];
int h[Maxn];

int main(){
    int n;
    cin >> n;
    vector<int> t(n), a(n);

    fix[0] = fix[n - 1] = true;
    REP(i,0,n){
        cin >> t[i];
        if (i == 0) h[0] = t[0];
        else if (t[i] > t[i - 1]){
            fix[i] = true;
            h[i] = t[i];
        }
    }
    REP(i,0,n){
        cin >> a[i];
    }

    if (a[0] != t[n - 1]){
        cout << 0 << endl;
        return 0;
    }
    RREP(i,n - 1,0){
        if (i == n - 1) h[n - 1] = a[n - 1];
        else if (a[i] > a[i + 1]){
            if (fix[i] == true && h[i] != a[i]){
                cout << 0 << endl;
                return 0;
            }

            fix[i] = true;
            h[i] = a[i];
        }
    }

    int tmp = h[0];
    REP(i,1,n){
        if (fix[i]) tmp = h[i];
        else h[i] = tmp;
    }
    tmp = h[n - 1];
    RREP(i,n - 2,0){
        if (fix[i]) tmp = h[i];
        else h[i] = min(h[i], tmp);
    }

    ll ans = 1LL;
    REP(i,0,n){
        if (!fix[i]) (ans *= h[i]) %= MOD;
    }

    REP(i,0,n){
        if (t[i] < h[i] || a[i] < h[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    
    return 0;
}