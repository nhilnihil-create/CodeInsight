#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll r = 1000000007;

ll np(int a){
    ll ans=1;
    while(a>0){
        ans *= a;
        ans %= r;
        a--;
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;
    if(abs(n-m) > 1){
        cout << 0 << endl;
    }
    else if(abs(n-m) == 1){
       cout <<(np(n)*np(m))%r << endl;
    }
    else{
        cout << (2*np(n)*np(m))%r << endl;
    }
    return 0;
}