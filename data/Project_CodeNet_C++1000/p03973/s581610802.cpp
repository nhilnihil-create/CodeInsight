#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll ans = 0;

    ll mi = 0;
    rep(i,n){
        if(i==0){
            ans += a[i] - 1;
            mi = 1;
        }else{
            if(a[i]<=mi){
                continue;
            }if(a[i]==mi+1){
                mi = a[i];
            }else{
                ll loop = (a[i] - (mi+2)) / (mi+1);
                ans += loop;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
 
 
