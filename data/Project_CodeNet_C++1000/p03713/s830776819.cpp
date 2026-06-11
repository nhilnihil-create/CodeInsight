#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return (a / g) * b;
}

//重みある時
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

int main() {
    ll H,W,ans;
    cin >> H >> W;
    ans = H*W;
    vector<ll> s(3);
    for (int h = 1; h <= H-1; ++h) {
        s[0] = h*W;
        s[1] = (H-h)*(W/2);
        s[2] = (H*W-s[0]-s[1]);
        sort(s.begin(),s.end());
        ans = min(ans,s[2]-s[0]);

        s[0] = h*W;
        s[1] = (H-h)/2*W;
        s[2] = (H*W-s[0]-s[1]);
        sort(s.begin(),s.end());
        ans = min(ans,s[2]-s[0]);
    }

    swap(H,W);

    for (int h = 1; h <= H-1; ++h) {
        s[0] = h*W;
        s[1] = (H-h)*(W/2);
        s[2] = (H*W-s[0]-s[1]);
        sort(s.begin(),s.end());
        ans = min(ans,s[2]-s[0]);

        s[0] = h*W;
        s[1] = (H-h)/2*W;
        s[2] = (H*W-s[0]-s[1]);
        sort(s.begin(),s.end());
        ans = min(ans,s[2]-s[0]);
    }
    cout << ans << endl;
    return 0;
}