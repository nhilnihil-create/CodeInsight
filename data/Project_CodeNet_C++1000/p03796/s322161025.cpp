#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

const int MOD = 1000000007;

int main(){
    ll n; cin>>n;
    
    ll power = 1;
    for(int i=1; i<=n; i++){
        power *= i;
        power %= MOD;
    }
    
    cout << power << endl;
    
    return 0;
}