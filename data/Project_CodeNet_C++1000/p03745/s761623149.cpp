#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,j,n) for(int i=j ; i < (int) (n) ; ++i )
#define rep(i,n) for(int i=0 ; i < (int) (n) ; ++i )

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ary[n];
    rep(i,n) cin >> ary[i];

    if (n==1)
    {
        cout << 1 << endl;
    }
    else
    {
        int updown = 0;
        int cnt = 1;
        rep(i,n-1)
        {
            if (updown==0)
            {
                updown = ary[i+1]-ary[i];
                if (updown==0) continue;
                updown /= abs(updown);
            }
            else if ((ary[i+1]-ary[i])/updown<0)
            {
                // cout << i << " " << updown << endl;
                cnt++;
                updown = 0;
            }
            else
            {
                // pass
            }
            
        }
        cout << cnt << endl;
    }
}


