#include<bits/stdc++.h>
#define ll long long
#define inf 999999999999
#define F first
#define S second
#define pb push_back
#define read(x)  freopen("input.txt","r",stdin);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 100000+100
using namespace std;
ll m[mx],s[mx];
vector<ll>v;
int main(){//read(x);
//fast;
ll a,b,c,d,e,f,g,h,i,j,k,l=0,n,t;
c=0;
cin>>n>>k;
for(i=1;i<=n;i++){
    cin>>m[i];
    s[i]=m[i]+s[i-1];
}l=1;h=n;a=0;
b=s[n];
for(i=1;i<n;i++){
    a=m[i]+m[i+1];
    if(a>=k){
        c++;
        v.pb(i);
    }
}

if(c==0)cout<<"Impossible\n";
else if(v.size()==n-1){
    cout<<"Possible\n";
    for(i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
else{
    cout<<"Possible\n";
    for(i=1;i<v[v.size()-1];i++)cout<<i<<endl;
    for(i=n-1;i>v[v.size()-1];i--)cout<<i<<endl;
    cout<<v[v.size()-1]<<endl;
}
//v.clear();
//main();
}












