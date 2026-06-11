#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

 
int main() {
    ll n,m;
    cin>>n>>m;
    ll scc=0;
    if(2*n>=m)cout<<m/2<<endl;
    else cout<<n+(m-2*n)/4<<endl;
}