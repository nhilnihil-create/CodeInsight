#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll x = a+b*(n-1);
    ll y = a*(n-1)+b;
    cout << max((ll)0,x-y+1) << endl;
    return 0;
}