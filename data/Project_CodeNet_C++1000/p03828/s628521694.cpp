#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;

void factor(int a,map<int,ll>& factors){
    for(int i=2;i*i<=a;i++){
        if(0==a%i)
        while(0==a%i){
            a/=i;
            factors[i]++;
        }
    }
    if(1!=a) factors[a]++; 
    return;
}
int main(){
    int n;
    cin>>n;
    map<int,ll> factors;
    for(int i=1;i<=n;i++){
        factor(i,factors);
    }
    ll ans=1;
    for(const auto& item: factors){
        ans*=(item.second+1);
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
