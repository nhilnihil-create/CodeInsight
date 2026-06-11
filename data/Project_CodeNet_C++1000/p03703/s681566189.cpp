#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

ll a[200005];
ll s[200005];
P p[200005];
int r[200005];

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= k;
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
    for(int i = 0; i <= n; i++) p[i] = P(s[i], i);
    sort(p, p + n + 1);
    for(int i = 0; i <= n; i++) r[p[i].second] = i;
    BIT<ll> bit(n + 2);
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += bit.sum(r[i]);
        bit.add(r[i], 1);
    }
    cout << ans << endl;
}
