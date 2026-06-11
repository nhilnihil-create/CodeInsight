#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
    rep(i,n){
        //iこmin
        if(-d*i + (n-1-i)*c <= b-a&& b-a <= -i*c + (n-1-i)*d ) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}
