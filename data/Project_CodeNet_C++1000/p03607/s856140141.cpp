#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
#define LEN(s) s.length();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

int main(){
    ll n, count = 1, ans = 0;
    cin >> n;

    ll a[n];
    rep(i,n)cin >> a[i];

    sort(a, a + n);

    rep(i, n){
        if(a[i] == a[i + 1]){
            count++;
        }
        else{
            if(count % 2 == 1){
                ans++;
            }
            count = 1;
        }
    }

    cout << ans << endl;

    return 0;
}

