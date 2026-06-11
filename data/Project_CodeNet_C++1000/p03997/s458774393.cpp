#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e8;

//少数点表示
//cout <<std::fixed << std::setprecision(14)

int main(){
    cin.tie( 0 ); ios::sync_with_stdio( false );
    int a,b,h,ans;
    cin >> a >> b >> h;
    ans=((a+b)*h)/2;
    cout << ans << endl;
}