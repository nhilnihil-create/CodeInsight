#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp fixed << setprecision
#define pb(x) push_back(x)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

//aとbの最大公約数
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

//aとbの最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

//ax+by=cの整数解(x,y)のうちの一つ
pll extgcd(ll a, ll b, ll c){
    if(b == 0){
        return pll(c/a, 0);
    }
    else{
        pll p = extgcd(b, a%b, c);
        ll x = p.second, y = p.first;
        return pll(x, y-(a/b)*x);
    }
}

int N;

//judge(v):=配列の状態がvであるときに手番で勝てるなら1,負けるなら0
int judge(vector<int> v){
    int g = v[0];
    for(auto &e: v) g = gcd(g, e);
    for(auto &e: v) e /= g;
    int cnt = 0, sum = 0;
    for(auto &e: v) sum += e, cnt += e&1;
    if(sum%2 == 0){
        if(N%2 == 0) return 0;
        else return 1;
    }
    else{
        if(N%2 == 0) return 1;
        elif(cnt > 1) return 0;
        else{
            for(auto &e: v){
                if(e == 1) return 0;
                if(e&1) e--;
            }
            return judge(v)^1;
        }
    }
}

int main(){
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    if(judge(v)) cout << "First" << endl;
    else cout << "Second" << endl;
}