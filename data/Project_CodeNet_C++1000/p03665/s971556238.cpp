#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// (2^x - 1) * 2^(n-x)
int main(){
    int n, p;
    cin >> n >> p;
    int one = 0;
    rep(i,n) {
        int a;
        cin >> a;
        if(a%2) one++;
    }
    if(one==0) {
        if(p==0) cout << (1LL<<n) << endl;
        else cout << 0 << endl;
    }
    else{
        cout << (1LL << (n-1)) << endl;
    }
    return 0;
}