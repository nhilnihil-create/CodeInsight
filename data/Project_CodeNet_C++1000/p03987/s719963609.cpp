#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;
#define Nmax 200005
#define OFF 100001
using namespace std;

int n,v[Nmax],R[Nmax],L[Nmax],mn,lst;
vector<pii> st;


int main()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> v[i];
    mn = 1e9;
    lst = 0;
    st.push_back({-1, 0});
    for (int i=1;i<=n;i++){
        while (st.back().first > v[i]) st.pop_back();
        L[i] = st.back().second;
        st.push_back({v[i],i});
    }
    st.clear();
    st.push_back({-1,n+1});
    for (int i=n;i>=1;i--){
        while (st.back().first > v[i]) st.pop_back();
        R[i] = st.back().second;
        st.push_back({v[i],i});
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = ans + 1LL * v[i] * (i - L[i]) * (R[i] - i);
    }

    cout << ans << '\n';

    return 0;
}
