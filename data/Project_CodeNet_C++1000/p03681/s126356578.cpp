#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;


int main() {
    int n,m;
    cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0<<endl;
        return 0;
    }
    ll nr=1,mr=1;
    //n!
    for(int i=1;i<=n;i++)nr=(nr*i)%MOD;
    //m!
    for(int i=1;i<=m;i++)mr=(mr*i)%MOD;
    if(n==m)cout<<(2*(nr*mr))%MOD<<endl;
    else cout<<(nr*mr)%MOD<<endl;
   
}