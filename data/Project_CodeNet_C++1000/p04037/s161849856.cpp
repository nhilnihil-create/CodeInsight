#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
// priority_queue <P,vector<P>,greater<P> > pqps;
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

ll n,m,num,sum,a,b,d,e,h,r,l,q;
ll w;
ll k;
ll x[500005], y[500005], z[500005];
char s[500005], t[500005];

bool islimit(ll i,ll j){
    ll compare;
    if(i >= n){
        compare = 0;
    }else{
        compare = x[i];
    }
    return (j >= compare);
}

int main(){
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> x[i];
    }
    if(n == 1){
        if(x[0] % 2 == 0){
            p("First");
        }else{
            p("Second");
        }
        return 0;
    }
    sort(x, x + n);
    reverse(x, x + n);
    ll cnt = 1;
    vector<ll> len;
    bool first = true;
    for(ll i=n-1;i>=0;i--){
        ll dif = x[i] - x[i+1];
        if(dif == 0){
            cnt ++;
        }else{
            if(first){
                first = false;
            }else{
                len.pb(cnt);
            }
            len.pb(dif);
            cnt = 1;
        }
    }
    len.pb(cnt);
    /*
    for(ll i=0;i<len.size();i++){
        pe(len[i]);
    }
    el;
    */
    ll sum = 0;
    bool res = false;
    for(ll i=0;i<len.size()/2;i++){
        ll idx1 = i * 2;
        ll idx2 = i * 2 + 1;
        sum += len[idx1];
        if(sum >= n){
            if(sum == n)res = true;
            if((sum - n) % 2 == 0)res = true;
            break;
        }
        sum += len[idx2];
        if(sum >= n){
            if(sum == n && len[idx2] % 2 == 0){
                if(len[idx2+1] % 2 == 0)res = true;
            }else if((n - sum + len[idx2]) % 2 == 0){
                res = true;
            }
            break;
        }
    }
    if(res){
        p("Second");
    }else{
        p("First");
    }
    return 0;
}
















