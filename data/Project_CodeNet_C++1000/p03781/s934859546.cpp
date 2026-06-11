#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    ll x; cin>>x;
    int sum=0;
    for(int i=1;i<100000;i++){
        sum+=i;
        if(sum>=x){
            cout<<i<<endl;
            return 0;
        }
    }

}
