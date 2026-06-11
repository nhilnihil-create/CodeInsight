#include <bits/stdc++.h>

using namespace std;

#define PB push_back
void parr(int *arr, int n){ for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl; }
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll n,a,b;
ll m;
const int N = 1e8;
ll h[N];

bool OK(ll x){
    ll s = x;
    for (int i = 0; i < n; i++){
        if (h[i]-(x*b) <= 0) {
            continue;
        }
        if (h[i]-(s*a + ((x-s)*b)) > 0) {
            return false;
        }
        ll k;
        ll l = 1;
        ll r = s;
        while (l < r){
            k = (l+r)/2;
            if (h[i]-((k*a)+((x-k)*b)) > 0) {
                l = k+1;
            } else {
                r = k;
            }
        }
        s -= r;
    }
    return true;
}

int main(){
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    cin >> n >> a >> b;
    
    for (int i = 0; i < n; i++){
        cin >> h[i];
        if (h[i] > m) {
            m = h[i];
        }
    }

    ll l = 1, r = 1 + ((m-1) / b), k;
    while (l<r){
        k = (l+r)/2;
        if (OK(k)) {
            r = k;
        } else {
            l = k +1;
        }
    }
    cout << r << endl;

    return 0;
}
