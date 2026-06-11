#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
lol gcd(lol a,lol b);
lol lcm(lol a,lol b);
int main(){
    lol n;
    cin>>n;
    vector<lol> t(n+10,1);
    for(lol i=0;i<n;i++){
        cin>>t[i];
    }
    lol ans=lcm(t[0],t[1]);
    for(lol i=2;i<n;i++){
        ans=lcm(ans,t[i]);
    }
    cout<<ans<<"\n";
    return(0);
}

lol gcd(lol a,lol b){
    while(b!=0){
        lol r=a%b;
        a=b;
        b=r;
    }
    return(a);
}

lol lcm(lol a,lol b){
    return(a/gcd(a,b)*b);
}