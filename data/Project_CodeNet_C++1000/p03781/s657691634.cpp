

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/



////////////////////////////////////////

ll calc(ll k){
    return k*(k+1)/2;
}


int main(){
   
    ll x;cin>>x;
    ll l=0,r=100000;
    while(l<r){
        ll m=(l+r)/2;
        if(x<=calc(m))r=m;
        else l=m+1;
    }
    cout<<l<<endl;
    
    return 0;
}