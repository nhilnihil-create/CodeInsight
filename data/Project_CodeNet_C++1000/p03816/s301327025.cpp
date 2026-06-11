#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    FAST
    ll n;
    cin>>n;
    ll x;
    map<ll,ll>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        m[x]++;
    }
    int y,count1=0,count2=0;
    for(auto pair:m){
        if(m[pair.first]>2){
            y=m[pair.first];
            while(!(y<3)){
                y=y/3 + y%3;
            }
            m[pair.first]=y;
        }
        if(m[pair.first]==2)count1++;
        else count2++;
    }
    if(count1%2==0)cout<<count1+count2;
    else cout<<count1+count2-1;
    
}