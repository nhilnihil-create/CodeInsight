#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>> pque;
priority_queue<ll> pque1;
ll n,s[300000],ans1[100001],ans2[100001],su2,su1,ans=-1e15,p;
int main(void){
    cin>>n;
    for(int i=0;i<n*3;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        pque.push(s[i]);
        su1+=s[i];
        pque1.push(s[3*n-i-1]);
        su2+=s[3*n-i-1];
    }
    ans1[0]=su1;
    ans2[0]=su2;
    for(int i=0;i<n;i++){
        su1+=s[n+i];
        pque.push(s[n+i]);
        p=pque.top();
        //cout<<p<<endl;
        su1-=p;
        pque.pop();
        ans1[i+1]=su1;
        
        su2+=s[2*n-1-i];
        pque1.push(s[2*n-1-i]);
        p=pque1.top();
        //cout<<p<<endl;
        su2-=p;
        pque1.pop();
        ans2[i+1]=su2;
    }
    for(int i=0;i<n+1;i++){
        //cout<<ans1[i]<<" "<<ans2[n-i]<<endl;
        ans=max(ans,ans1[i]-ans2[n-i]);
    }
    cout<<ans<<endl;
}
