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
        ll tmp=1;
        ll mymax=a[0];
        ll money=0;
        for(int j=0;j<n-1;j++){
            if(((1<<j)&bit)==0){
                if(mymax>=a[j+1]){
                    money+=(-a[j+1]+mymax)+1;
                    mymax++;
                }
                tmp++;
            }else if(mymax<a[j+1]){
                tmp++;
            }
            mymax=max(mymax,a[j+1]);
        }
        if (tmp>=k) {
            ans=min(ans,money);
        }
    }

    cout<<ans<<endl;

}