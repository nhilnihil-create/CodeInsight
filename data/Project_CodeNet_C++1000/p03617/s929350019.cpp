#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll ans = 0;
    if(d <= 4*h && d <= 2*s && d <= 8*q){
        ans += (n / 2) * d;
        n %= 2;
    }
    if(8*q <= 4*h && 8*q <= 2*s){
        ans += 4 * n * q;
    }else if(4*h <= 8*q && 4*h <= 2*s){
        ans += 2 * n * h;
    }else if(2*s <= 8*q && 2*s <= 4*h){
        ans += n * s;
    }

    cout << ans << endl;


    return 0;
}