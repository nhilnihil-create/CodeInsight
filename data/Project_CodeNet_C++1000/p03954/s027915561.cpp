#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//↓,→,↑,←
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
// #define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
 
// ll mod = 998244353;
 ll mod = 1000000007;
  
ll mypow(ll number1,ll number2, ll mod){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
 
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 
/*
ll fact[fact_table + 5],rfact[fact_table + 5];
 
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = rui(fact[fact_table],mod - 2);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
bool multicase = false;

ll n,m,num,sum,a,b,c,d,e,h,q;
ll w, ans;
ll k;
char s[500005], t[500005];
ll x[500005], y[500005];

void init(){
    struct timeval _time;
    gettimeofday(&_time, NULL);
    ll usec = _time.tv_usec * 1000000;
    srand(usec);
    return;
}

bool calc(ll mid){
    vector<ll> v;
    //p(mid);
    for(ll i=0;i<n;i++){
        v.pb(x[i] >= mid);
    }
    ll l, r;
    if(v[(n-1)/2] == 1){
        l = (n-1)/2, r = (n-1)/2;
    }else{
        l = (n-1)/2 + 1, r = (n-1)/2 - 1;
    }
    while(true){
        if(v[l-1] == 0 && v[l-2] == 1 && l-2 >= 0){
            l -= 2;
        }else{
            break;
        }
    }
    while(true){
        if(v[r+1] == 0 && v[r+2] == 1 && r+2 < n){
            r += 2;
        }else{
            break;
        }
    }
    //pe(l);p(r);
    if(!(l <= (n-1)/2 && (n-1)/2 <= r)){
        return (v[(n-1)/2] == 1);
    }
    if(l == 0 && r == n - 1){
        return true;
    }
    if((l + r) / 2 == (n-1)/2){
        return (v[r+1] == 1) || (v[l-1] == 1);
    }else{
        ll center = (l + r) / 2;
        if(center < (n-1)/2){
            return (v[r+1] == 1);
        }else{
            return (v[l-1] == 1);
        }
    }
}

void solve(){
    cin >> n;
    n = 2 * n - 1;
    for(ll i=0;i<n;i++){
        cin >> x[i];
    }
    if(n <= 3000){
        vector<ll> v, u;
        for(ll i=0;i<n;i++){
            v.pb(x[i]);
        }
        while(n > 1){
            for(ll i=0;i<n-2;i++){
                y[0] = v[i], y[1] = v[i+1], y[2] = v[i+2];
                sort(y, y + 3);
                u.pb(y[1]);
            }
            v.clear();
            for(ll i=0;i<u.size();i++){
                v.pb(u[i]);
            }
            u.clear();
            n -= 2;
        }
        p(v[0]);
        return;
    }
    // 真ん中はn-1
    ll ok = 1, ng = n + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        bool res = calc(mid);
        if(res){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    p(ok);



    return;
}

int main(){
    // init();
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        solve();
    }
    return 0;

}
















