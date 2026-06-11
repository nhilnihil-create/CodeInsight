#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;
set<int>st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    st.insert(0);
    st.insert(n+1);
    vector<pair<int,int>>v;
    f1(n) {
        int x;
        cin >> x;
        v.pb({x,i});
    }
    sort(all(v));
    ll ans = 0;
    for (auto &i : v) {
        int x = *st.lower_bound(i.S);
        int y = *prev(st.lower_bound(i.S));
        ans += (ll)(x - i.S) * (i.S - y) * i.F;
        st.insert(i.S);
    }
    cout << ans << '\n';
}
