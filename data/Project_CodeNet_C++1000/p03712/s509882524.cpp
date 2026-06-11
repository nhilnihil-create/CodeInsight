#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int MAX=1e5+10;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int h,w; 
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    rep(i,w+2) cout << '#';
    cout << endl;
    rep(i,h) {
        cout << '#' << a[i] << '#' << endl;
    }
    rep(i,w+2) cout << '#';
    cout << endl;
     
    return 0;   
}