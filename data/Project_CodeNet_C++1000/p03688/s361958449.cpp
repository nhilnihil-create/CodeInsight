#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int n,a,r1,r2=INF,cnt1=1,cnt2;
bool f=true;

signed main() {
    cin >> n >> r1;
    rep(i,n-1) {
        cin >> a;
        if (r1 == a) cnt1++;
        else if (abs(r1-a)==1) {
            if (f) r2 = a, cnt2++, f=false;
            else if (r2 == a) cnt2++;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (r1 > r2) {
        swap(r1,r2);
        swap(cnt1, cnt2);
    }
    if (!cnt2) {
        if (n-1 == r1 || r1*2 <= n) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        n -= cnt1;
        r2 -= cnt1;
        if (r2 < 1) cout << "No" << endl;
        else if (r2*2 <= n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}



