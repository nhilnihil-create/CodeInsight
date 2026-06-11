#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n;
    cin >> n;
    ll a[100005];
    P p[100005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n, greater<P>());
    a[n] = 0;
    p[n] = P(0, n);
    ll ans[100005];
    ll c = 0, l = n, h = 0, s = 0;
    for(int i = 0; i < n + 1; i++){
        int j = p[i].second;
        s += (h - a[j]) * c;
        h = a[j];
        c++;
        if(j < l || j == n){
            ans[l] = s;
            s = 0;
            l = j;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}
