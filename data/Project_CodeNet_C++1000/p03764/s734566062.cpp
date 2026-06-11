#include<iostream>
using namespace std;
long long mod = 1000000007;
int main(){
    long long n,m,x,y;
    long long xsum,ysum,ans;
    cin >> n >> m;
    xsum = 0;
    ysum = 0;
    for(long long i=1;i<=n;i++){
        cin >> x;
        xsum += (2*i-n-1)*x;
        xsum %= mod;
    }
    for(long long i=1;i<=m;i++){
        cin >> y;
        ysum += (2*i-m-1)*y;
        ysum %= mod;
    }
    ans = xsum * ysum % mod;
    cout << ans << endl;
    return 0;
}
