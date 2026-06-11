/**
	如约而至是多么美好的词，等的辛苦，却不辜负
**/
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
ll n, m,x=0,y,z,h,t,q,l,temp=0,cnt1=0,cnt2=0,s[maxn],st2[maxn],w[maxn],ans = 0, k,flag1;
ll dp[maxn],a[maxn];
string s1,s2[maxn];
int main(){
    scanf("%lld%lld",&n,&l);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(ll i=1;i<n;i++)
    {
        if(a[i]+a[i+1]>=l){
            temp=1;
            flag1=i;
            break;
        }
    }
    if(!temp) printf("Impossible");
    else{
        printf("Possible\n");
        for(ll i=1;i<flag1;i++)
            printf("%lld\n",i);
        for(ll i=n-1;i>=flag1;i--)
            printf("%lld\n",i);
    }
	return 0;
}
