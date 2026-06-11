#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[300005];
ll A[300005],B[300005];
void prll(multiset<ll>st)
{
    for(auto it=st.begin();it!=st.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
#define inf -1000000000000000
int main()
{
    ll n;cin>>n;
    for(ll i=0;i<3*n;i++)cin>>ara[i];
    multiset<ll>st;
    multiset<ll,greater<ll>>ss;
    multiset<ll,greater<ll>>::iterator ii;
    multiset<ll>::iterator it;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=ara[i];
        st.insert(ara[i]);
    }
    A[n-1]=sum;
    for(ll i=n;i<2*n;i++)
    {
        it=st.begin();
        if(*it<ara[i]){

//            cout<<"eraseing "<<endl;
            sum=sum+ara[i]-*it;
            st.erase(it);
            st.insert(ara[i]);
//            prll(st);
        }
        A[i]=sum;
    }
//    for(ll i=n-1;i<=2*n;i++)cout<<A[i]<<" ";cout<<endl;
    sum=0;
    for(ll i=3*n-1;i>=2*n;i--)
    {
        sum+=ara[i];
        ss.insert(ara[i]);
    }
    B[2*n]=sum;
    for(ll i=2*n-1;i>=n;i--)
    {
        ii=ss.begin();
        if(*ii>ara[i])
        {
//            cout<<"i = "<<i<<
            sum=sum+ara[i]-*ii;
            ss.erase(ii);
            ss.insert(ara[i]);
        }
        B[i]=sum;
    }
    ll ans=inf;
    for(ll i=n-1;i<2*n;i++)
    {
        ll temp=A[i]-B[i+1];
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
}
