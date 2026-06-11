#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;

ll f(ll a,ll b){
    if(a<=b) {
        if(b%a==0) return 2*a*(b/a) - a; 
        else return 2 * a *(b/a) + f(a,b%a);
    }else {
        if(b==0) return 0;
        else return f(b,a);
    }  
}

int main() {
    ios::sync_with_stdio(0);
    cin>>n>>x;
    cout<<n + f(x,n-x)<<endl;
    return 0;
}


