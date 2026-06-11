#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    ll a[3];rep(i,3)cin>>a[i];
    sort(a,a+3);
    co(a[0]*a[1]*(a[2]%2));
}