#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N = pow(10,9)+7;

ll factorial(ll a){
    ll ans = 1;
    for(int i=1; i<=a; i++){
        ans = (ans*i)%N;
    }
    return ans;
}

int main(){
    ll n,m;
    cin >> n >> m;
    if(abs(n-m)>1){
        cout << 0 << endl;
        return 0;
    }
    if(n==m){
        cout << (2*factorial(n)*factorial(m)) % N << endl;
        return 0;
    }
    else{
        cout << (factorial(n)*factorial(m)) % N << endl;
        return 0;
    }
}