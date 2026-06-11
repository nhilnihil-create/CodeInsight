#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N,M,tmp,ans;
    cin>>N>>M;
    tmp = M;
    tmp -= (N*2);
    
    if(tmp < 0){
        ll kake = M/2;
        ans = kake;
    }

    else{
        ans = N;
        ans += (tmp/4);
    }

    cout<<ans<<endl;

    return 0;
}