#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=2e9;
ll a[N],val[N],n,ps[N],ans[N];

ll get(ll x)
{
    int tmp=upper_bound(val+1,val+n+1,x)-val;
    return ps[tmp]-x*(n-tmp+1);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],val[i]=a[i];
    sort(val+1,val+n+1);
    for (int i=n;i;i--) ps[i]=ps[i+1]+val[i];
    vector<int> st;
    a[n+1]=inf;
    st.pb(n+1);
    for (int i=n;i;i--)
    {
        while (a[i]>=a[st.back()]) st.pop_back();
        st.pb(i);
    }
    st.pb(0);
    for (int i=1;i<(int)st.size()-1;i++)
    {
        int x=st[i],y=st[i+1];
        ans[x]=get(a[y])-get(a[x]);
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}
