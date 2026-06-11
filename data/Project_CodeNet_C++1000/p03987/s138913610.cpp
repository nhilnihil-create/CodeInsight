#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
typedef long long ll;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
map<ll,ll>mp;
queue<int>q1;
deque<int>q2;
stack<int>st;
ll n, m,x,y,z,h,t,temp=0,s[maxn],flag,st2[maxn],w[maxn],ans = 0, k,flag1=10,flag2=0;
ll l[maxn],r[maxn],a[maxn];
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        l[i]=0;
        r[i]=n+1;
    }
    for(ll i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]>a[i]){
            r[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    for(ll i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]>a[i]){
            l[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    ///for(ll i=1;i<=n;i++) cout << l[i] << " ";
    for(ll i=1;i<=n;i++)
    {
        ans+=a[i]*(i-l[i])*(r[i]-i);
    }
    cout << ans;
    return 0;
}
