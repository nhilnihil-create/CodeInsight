#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
 
int main(){
    ll n,x;
    cin >> n >> x;
    cout << 3*(n-__gcd(n,x)) << endl;
}