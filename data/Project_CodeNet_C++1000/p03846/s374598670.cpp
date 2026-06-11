#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int a[100010];

int main () {

    int n;cin>>n;

    rep(i,n) cin>>a[i];

    sort(a,a+n);

    if (n%2==0) {
        ll ans=1;
        for (int i=0;i<n;i+=2) {
            if (a[i]!=i+1||a[i+1]!=i+1) {
                cout<<0<<endl;
                return 0;
            }
            ans=ans*2%MOD;
        }
        cout<<ans%MOD<<endl;
    } else {
        ll ans=1;
        if (a[0]!=0) {
            cout<<0<<endl;
            return 0;
        }
        for (int i=1;i<n;i+=2) {
            if (a[i]!=i+1||a[i+1]!=i+1) {
                cout<<0<<endl;
                return 0;
            }
            ans=ans*2%MOD;
        }
        cout<<ans%MOD<<endl;
    }

}