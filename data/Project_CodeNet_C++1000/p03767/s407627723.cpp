#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;
    int a[3*n];rep(i,3*n)cin>>a[i];
    sort(a,a+(3*n),greater<int>());
    ll ans = 0;
    for(int i=0;i<2*n;i++){
        if(i%2==1){ans += a[i];}
    }
    co(ans);
}