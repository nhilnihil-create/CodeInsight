#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;

    ll maxn = 0;
    for(long long i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            maxn = max(maxn, i);
        }
    }
    put(max(to_string(maxn).size(),to_string(n / maxn).size()));
}