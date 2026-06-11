#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

long long mod = pow(10,9)+7;
long long func(long long n){
    long long ans=1;
    while(n>0){
        ans*=n;
        ans = ans%mod;
        n--;
    }
    return ans;
}


int main() {
    long long N,M; cin>>N>>M;
    long long ans=1;
    if(abs(N-M)>=2) cout << 0 << endl;
    else{
        ans *= func(N); 
        ans *= func(M); 
        if(N==M) cout << ans*2%mod << endl;
        else cout << ans%mod << endl;
    }
}

