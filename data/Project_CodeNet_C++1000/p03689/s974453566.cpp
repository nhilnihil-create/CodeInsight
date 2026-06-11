#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

// 1-indexed 2d BIT
class BIT2{
    public:
    ll H, W;
    vector<vector<ll> >bit;
    BIT2(ll _H, ll _W){
        H = _H + 5;
        W = _W + 5;
        bit.resize(_H + 10, vector<ll>(_W + 10, 0));
    }
    void add_point(ll x, ll y, ll v){
        for(ll Y = y; Y <= H; Y += Y & -Y){
            for(ll X = x; X <= W; X += X & -X){        
                bit[Y][X] += v;
            }
        }
    }
    ll get_sum(ll x, ll y){
        if(x <= 0 || y <= 0)return 0;
        if(x > W || y > H)return 0;
        ll sum = 0;
        for(ll Y = y; Y > 0; Y -= Y & -Y){
            for(ll X = x; X > 0; X -= X & -X){
                sum += bit[Y][X];
            }
        }
        return sum;
    }
    ll get_sum(ll x1, ll y1, ll x2, ll y2){
        ll tmp = 0;
        tmp += get_sum(x2, y2);
        tmp -= get_sum(x2, y1 - 1);
        tmp -= get_sum(x1 - 1, y2);
        tmp += get_sum(x1 - 1, y1 - 1);
        return tmp;
    }
};

int main(){

    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }
    BIT2 bit(H, W);
    ll a = 999999999 / (h * w - 1);
    ll total = a * H * W;
    rep1(y, H)rep1(x, W){
        bit.add_point(x, y, a);
    }
    rep1(y1, H + 1 - h)rep1(x1, W + 1 - w){
        ll x2 = x1 + w - 1;
        ll y2 = y1 + h - 1;
        ll sum = bit.get_sum(x1, y1, x2, y2);
        if(sum < 0)continue;
        bit.add_point(x2, y2, - (sum + 1));
        total -= (sum + 1);
    }
    if(total <= 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep1(y, H){
        rep1(x, W){
            cout << bit.get_sum(x, y, x, y);
            if(x == W)cout << endl;
            else cout << " ";
        }
    }
    return 0;
}