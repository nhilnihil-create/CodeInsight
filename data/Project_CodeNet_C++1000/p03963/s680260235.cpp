#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

//繰り返し二乗法
ll ex(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==1)return ex(x,n-1)*x;
    else return ex(x*x,n/2);
};

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    ll ans = k;
    ans *= ex(k-1,n-1);
    cout << ans << endl;
}