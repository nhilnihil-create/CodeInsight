#include<bits/stdc++.h>
using namespace std;

#define REP(i,x,y) for(ll i=x; i<=y; i++)
#define BIT(t) ((long long 1) << t)
#define PER(i,y,x) for(ll i=y; i>=x; i--)
#define SIZE(v) ll(v.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
typedef long long ll;

ll gcd(ll x,ll y){
    if(y == 0){
        return x;
    }else{
        return gcd(y, x % y);
    }
}

ll f(ll n, vll& a){
    ll odd = 0;
    ll even = 0;
    ll oddi = -1;
    REP(i,0,n-1){
        if(a[i] % 2){
            odd++;
            oddi = i;
        }else{
            even++;
        }
    }
    if(even % 2 == 1){
        return 0;
    }else if(odd >= 2){
        return 1;
    }else{
        if(a[oddi] == 1){
            return 1;
        }
        a[oddi]--;
        ll tmp = gcd(a[0], a[1]);
        REP(i,2,n-1){
            tmp = gcd(tmp, a[i]);
        }
        REP(i,0,n-1){
            a[i] /= tmp;
        }
        return 1 + f(n, a);
    }
}

int main(){
    ll n;
    cin >> n;
    vll a;
    REP(i,1,n){
        ll tmp; cin >> tmp;
        a.push_back(tmp);
    }
    ll ans = f(n, a);
    if(ans % 2 == 0){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
}

