#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ll i,j,k,l,m,n;

    cin >> n;

    ll L[n+10],R[n+10],ar[n+10];
memset(L,-1,sizeof L);

    for(i = 0 ; i < n ; i++)cin >> ar[i],R[i] = n;

    stack<ll>st;

    for(i = 0 ; i < n ; i++)
    {
        while(!st.empty() && ar[st.top()] >= ar[i])
            st.pop();
       if(!st.empty())L[i] = st.top();
        st.push(i);
    }

    while(!st.empty())st.pop();

    for(i = n-1 ; i >= 0 ; i--)
    {
        while(!st.empty() && ar[st.top()] >= ar[i])st.pop();
        if(!st.empty())R[i] = st.top();
        st.push(i);
    }

     while(!st.empty())st.pop();

     ll ans = 0;
    for(i = 0 ; i < n ; i++)
    {
        ans += ((i-L[i])*(R[i]-i))*ar[i];
    }

    cout << ans << endl;
}
