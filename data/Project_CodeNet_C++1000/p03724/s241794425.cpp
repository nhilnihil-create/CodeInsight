#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*[check]
木のパスはa-bに対して全て違う。
loopのみで構成されていないと条件を満たさない。
loopのみで構成=全偶数
*/

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        p[a]++; p[b]++;
    }

    bool even = true;
    rep(i, n){
        if (p[i]%2!=0) even=false;
    }
    if(even) cout << "YES" << endl;
    else cout << "NO" << endl; 
}
