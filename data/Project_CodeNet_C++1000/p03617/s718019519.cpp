#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long q,h,s,d,n,ans=0;
    cin>>q>>h>>s>>d>>n;
    if(q*2<h)
        h=q*2;
    if(h*2<s)
        s=h*2;
    if(s*2<d)
        d=s*2;
    ans+=(n/2)*d;
    n%=2;
    cout<<ans+n*s<<endl;
    return(0);
}