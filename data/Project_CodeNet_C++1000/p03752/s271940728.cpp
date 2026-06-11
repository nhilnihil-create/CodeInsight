#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max

int main ()  {
    cout << fixed << setprecision(18);

    int n,k;cin>>n>>k;

    ll a[20];
    rep(i,n) {
        cin>>a[i];
    }

    ll ans=99999999999999999;
    for (int bit=0;bit<(1<<(n-1));bit++) {
        int cnt=0;
        ll m=a[0];
        ll sum=0;
        rep(i,n-1) {
            if (bit & (1<<i)) {
                cnt++;
                if (a[i+1]-m<=0) {
                    sum+=m-a[i+1]+1;
                    m++;
                }
                else {
                    m=a[i+1];
                }
            }
            else {
                m=max(m,a[i+1]);
            }
        }
        if (cnt>=k-1) {
            ans=min(ans,sum);
        }
    }

    cout<<ans<<endl;

}
