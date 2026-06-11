#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N 100000
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int n;
vector<ll> a;
string ans[2] = {"First", "Second"};

ll gcd(ll x, ll y){
    while(y){
        x %= y;
        swap(x,y);
    }
    return x;
}

void solve(vector<ll> b, int now){
    ll g = 0;
    rep(i,b.size()) if(b[i]%2==0) g++;
    if(g&1){
        cout << ans[now] << endl;
        return;
    }
    if(b.size()-g != 1){
        cout << ans[now^1] << endl;
        return;
    }
    rep(i,b.size()){
        if(b[i]&1){
            if(b[i] == 1){
                cout << ans[now^1] << endl;
                return;
            }
            b[i]--;
            break;
        }
    }
    ll d = b[0];
    for(int i = 1; i < b.size(); i++){
        d = gcd(d,b[i]);
    }
    rep(i,b.size()) b[i] /= d;
    solve(b, now^1);
}

int main(){
    cin >> n;
    rep(i,n){
        ll tmp; cin >> tmp;
        a.push_back(tmp);
    }
    if(n == 1){
        puts("Second");
        return 0;
    }
    solve(a,0);
}
