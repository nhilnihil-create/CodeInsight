#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

const int MOD = 1000000007;

int main(){
    int n,k; cin>>n>>k;
    
    int ans = 1;
    
    rep(i,n){
        if(!i)ans *= k;
        else ans *= k-1;
    }
    
    cout << ans << endl;
    
    return 0;
}