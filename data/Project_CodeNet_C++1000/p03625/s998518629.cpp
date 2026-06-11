#include<bits/stdc++.h>
#define ll long long
#define inf 999999999999
#define F first
#define S second
#define read(x)  freopen("input.txt","r",stdin);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 200009
using namespace std;
priority_queue<ll>p,q;
map<ll,ll>m;
int main(){//read(x);
fast;
ll a,b,c,d,e,f,g,h,i,j,k,l=0,n,t;
cin>>n;
for(i=1;i<=n;i++){
    cin>>a;
    m[a]++;
}
for(auto i:m){
    a=i.F;b=i.S;
    if(b>=4)p.push(a);
    if(b>=2)q.push(a);
}
if(p.size()>=1){
    a=p.top();
    l=max(l,a*a);
}
if(q.size()>=2){
    a=q.top();q.pop();
    b=q.top();q.pop();
    l=max(l,a*b);
}

 cout<<l<<endl;

}












