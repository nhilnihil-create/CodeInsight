#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n),b(3);
    rep(i,n) {
        int in;
        cin >> in;
        while (in%2==0) {
            in/=2;
            ++a[i];
        }
        if (a[i]>1) ++b[2];
        else ++b[a[i]];
    }
    bool flag;
    if (b[1]>0) flag=(b[2]>=b[0]);
    else flag=(b[2]>=max(1,b[0]-1));

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    return 0;
}