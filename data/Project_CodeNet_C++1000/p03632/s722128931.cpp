#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a < c){
        a = c;
    }
    if(b > d){
        b = d;
    }
    int ans = b-a;
    if(ans <= 0) cout << 0 << endl;
    else cout << ans << endl;

    cout << endl;
    return 0;
}
