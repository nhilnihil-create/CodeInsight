#include <bits/stdc++.h>
using namespace std;
signed main(){
    long long x , ans;
    cin>>x;
    ans=(x/11)*2;
    x=x%11;
    if(x>0){
        ans++;
        x-=6;
    } 
    if(x>0){
        ans++;
        x-=5;
    }
    cout<<ans<<endl;
    return(0);
}