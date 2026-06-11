#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const ll mod=1000000007ll;

const ll hmax=100000;
const ll wmax=100000;


// x^n (mod を法として)
ll mod_pow(ll x,ll n,ll mod){
    ll r=1;
    while(n>0){
        if(n&1){
            r=r*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return r%mod;
}



ll mod_inv_prime(ll n,ll mod){
    return mod_pow(n,mod-2,mod)%mod;
}


ll mod_comb(ll n,ll k,ll mod,ll facttable[],ll factinvtable[]){
//    ll tm=facttable[n]*factinvtable[k];
//    tm%=mod;
//    tm*=factinvtable[n-k];
//    tm%=mod;
    return (((facttable[n]*factinvtable[k])%mod)*factinvtable[n-k])%mod;
}


int main(){

    ll h,w,a,b,ans,tm1,tm2;
    cin>>h>>w>>a>>b;

    ll facttable[h+w+2];
    ll factinvtable[h+w+2];

    //fact_tableを用意
    facttable[0]=1ll;
    ll tm=1;
    for(ll i=1;i<=w+h;i++){
        tm*=i;
        tm%=mod;
        facttable[i]=tm;
    }

    for(ll i=0;i<=w+h;i++){
        tm=facttable[i];
        factinvtable[i]=mod_inv_prime(tm,mod)%mod;
    }

    ans=0;
    for(ll i=1;i<=w-b;i++){
    //for(ll i=1;i<=100;i++){
    //    cout<<facttable[i]<<","<<factinvtable[i]<<endl;
        //cout<<h-a+b+i-2<<","<<h-a-1<<","<<h-a+b+i-2-(h-a-1)<<endl;
        //cout<<facttable[h-a+b+i-1]<<","<<factinvtable[a-1]<<","<<factinvtable[h-a+b+i-1-(a-1)]<<endl;
        //cout<<facttable[h-a+b+i-2]<<","<<factinvtable[h-a-1]<<","<<factinvtable[h-a+b+i-2-(h-a-1)]<<endl;
        //cout<<mod_comb(h-a+b+i-2,h-a-1,mod)<<","<<mod_comb(a+w-b-i-1,a-1,mod)<<endl;
        //cout<<(((facttable[h-a+b+i-1]*factinvtable[a-1])%mod)*factinvtable[h-a+b+i-1-(a-1)])%mod<<endl;
        /*
        tm=1;
        tm*=facttable[h-a+b+i-2];
        tm%=mod;
        tm*=factinvtable[h-a-1];
        tm%=mod;
        tm*=factinvtable[h-a+b+i-2-(h-a-1)];
        tm%=mod;
        tm*=facttable[a+w-b-i-1];
        tm%=mod;
        tm*=factinvtable[a-1];
        tm%=mod;
        tm*=factinvtable[a+w-b-i-1-(a-1)];
        tm%=mod;

        ans+=tm;
        */
        //cout<<facttable[a+w-b-i-1]<<","<<factinvtable[a-1]<<","<<factinvtable[a+w-b-i-1-(a-1)]<<endl;
        //ans+=((((facttable[h-a+b+i-2]*factinvtable[h-a-1])%mod)*factinvtable[h-a+b+i-2-(h-a-1)])%mod)*(((facttable[a+w-b-i-1]*factinvtable[a-1])%mod)*factinvtable[a+w-b-i-1-(a-1)]%mod);
        ans+=mod_comb(h-a+b+i-2,h-a-1,mod,facttable,factinvtable)*mod_comb(a+w-b-i-1,a-1,mod,facttable,factinvtable);
        ans%=mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}

