#include <bits/stdc++.h>
using namespace std ;
using ll=long long;
ll gcd(ll a,ll b){
    if(b==0){
        return(a);
    }else{
        return gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
int main(){
    ll  N;
    cin >> N;
    ll T[N];
    for(ll i=0;i<N;i++)cin>>T[i];
    ll Ans =T[0];
    for(ll i=1;i<N;i++){
        Ans=lcm(Ans,T[i]);
    }
    cout << Ans << endl;
}