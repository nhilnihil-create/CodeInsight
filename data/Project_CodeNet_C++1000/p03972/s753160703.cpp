#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll w, h;
    cin >> w >> h;
    ll p[w];
    rep(i,w)cin >> p[i];
    sort(p,p+w);
    ll q[h];
    rep(i,h)cin >> q[i];
    sort(q,q+h);
    ll ans = 0;
    ll i = 0;
    ll j = 0;
    while(true){
        if(i == w){
            if(j==h)break;
            ans += q[j];
            j++;
        }else if(j == h){
            ans += p[i];
            i++;
        }else{
            if(p[i] <= q[j]){
                ans += p[i] * (h + 1 - j);
                i++;
            }else{
                ans += q[j] * (w + 1 - i);
                j++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
 
 
