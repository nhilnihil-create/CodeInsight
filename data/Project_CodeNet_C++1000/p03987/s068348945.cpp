#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a[200005], b[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }
    ll l[200005], r[200005];
    for(int i = 0; i < n; i++){
        l[i] = -1;
        r[i] = n;
    }
    set<int> st;
    for(int i = 0; i < n; i++){
        auto itr = st.lower_bound(b[i]);
        if(itr != st.end()) r[i] = *itr;
        if(itr != st.begin()) l[i] = *--itr;
        st.insert(b[i]);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += (r[i] - b[i]) * (b[i] - l[i]) * (i + 1);
    }
    cout << ans << endl;
}
