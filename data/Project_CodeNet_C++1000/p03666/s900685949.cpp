#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=0;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x

using namespace std;

ll n, a, b, c, d;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    a = abs(a-b);
    n--;
    for (int i=0;i<=n;i++){
        ll x = -d * i + c * (n-i);
        ll y = d * (n-i) + -c * i;
        if (x <= a && a <= y){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
