

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

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////


int main(){
    ll k;cin>>k;
    ll p=k/50,q=k%50;
    ll a[50];for(int i=0;i<=49;i++)a[i]=p+49;
    while(q--){
        ll min=a[0],minx=0;
        for(int i=1;i<=49;i++)if(min>a[i]){min=a[i];minx=i;}
        for(int i=0;i<=49;i++){
            if(i==minx)a[i]+=50;
            else a[i]--;
        }
    }cout<<50<<endl;
    for(int i=0;i<=49;i++)cout<<a[i]<<" ";
    return 0;
}