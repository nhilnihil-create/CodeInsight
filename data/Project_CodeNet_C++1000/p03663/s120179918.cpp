#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;
const ll MAX=1e9;

bool query(ll x){
    cout<<"? "<<x<<endl;
    string S; cin>>S;
    if(S=="Y") return true;
    return false;
}
int main(){
    ll ans=0;
    bool K=query(MAX);
    ll COUNT=MAX/10;
    if(K){
        while(true){
            if(query(COUNT+1)) COUNT/=10;
            else break;
            if(COUNT==0) {ans=1; break;}
        }
        if(ans==0) ans=COUNT*10;
    }

    else{
        while(true){
            if(!query(COUNT)) COUNT/=10;
            else break;
        }

        ll NG=COUNT, OK=COUNT*10;
        OK--;
        while(OK-1>NG){
            ll MID=(OK+NG)/2;
            if(query(MID*10)) OK=MID;
            else NG=MID;
        }
        ans=OK;
    }
    cout<<"! "<<ans<<endl;


}