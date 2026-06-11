/* Author : icoder211 */

#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ln "\n"
#define mp make_pair
#define forn(i,e) for( i=0; i<e; i++)
#define forsn(i,s,e) for( i=s; i<e; i++)
#define rforn(i,e) for( i=e; i>=0; i--)
#define rforsn(i,s,e) for( i=e; i>=s; i--)
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<int>());

#define all(x) x.begin(), x.end()

#define out1(x1) cout << x1 << ln
#define out2(x1,x2) cout << x1 << " " << x2 << ln
#define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << ln
#define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << ln
#define out5(x1,x2,x3,x4,x5) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << ln
#define out6(x1,x2,x3,x4,x5,x6) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << ln

#define in1(x1) cin >> x1
#define in2(x1,x2) cin >> x1 >> x2
#define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
#define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4
#define in5(x1,x2,x3,x4,x5) cin >> x1 >> x2 >> x3 >> x4 >> x5
#define in6(x1,x2,x3,x4,x5,x6) cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6

#define arrin(a,n) forn(i,n) cin >> a[i];
#define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
ll exp(ll n, ll m, ll md){
        ll a = 1;
        while (m > 0){
                if (m&1) a = (a * n%md) % md;
                m /= 2;
                n = (n*n) % md;
        }
        return a % md;
}
void disp(vll v){
        for(auto u:v)
                cout<<u<<" ";
        cout<<"\n";
}
ll gcd2(ll a, ll b){
        return b ? gcd2(b, a%b) : a;
}
bool naiveprime(ll n) {
        if (n < 2) return false;
        for (ll x = 2; x*x <= n; x++) {
                if (n%x == 0) return false;
        }
        return true;
}
bool check_composite_for_prime_function(ll n, ll a, ll d, int s){
        ll x = exp(a, d, n);
        if (x == 1 || x == n-1) return false;
        for(int r = 1;r < s;++r){
                x = x * x%n;
                x %= n;
                if(x == n-1) return false;
        }
        return true;
}
bool prime(ll n){
        if(n < 4) return n == 2 || n == 3;
        if (!(n&1)) return false;
        int s = 0;
        ll d = n-1;
        while(!(d&1)){
                d >>= 1;
                s++;
        }
        for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
                if(n == a) return true;
                if(check_composite_for_prime_function(n, a, d, s)) return false;
        }
        return true;
}

const int NPR = 10000000;
int lp[NPR + 1];
vector<int> pr;
void prfac(int n = NPR){
        if (n > NPR) return;
        int i, j;
        forn(i, n) lp[i] = 0;
        for (  i =2;i <= n;++i) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        pr.push_back(i);
                }
                for ( j = 0; j < (int)pr.size() && pr[j] <= lp[i]; ++j) {
                        long long a = i * pr[j];
                        if(a <= n) lp[a] = pr[j];
                }
        }
}

//#define DEBUG
#ifdef DEBUG

#endif


void go1(){
        int n;
        cin >> n;
        int i, j, k;
        pll a[n];
        ll b[n];
        forn(i, n){
                cin >> a[i].F;
                b[i] = a[i].F;
                a[i].S = i;
        }
        sort(a, a+n);

        ll ans= 0;
        ll parity[n];
        forn(i, n){
                if(i & 1){
                        parity[a[i].S] = 0;// odd place
                }
                else{
                        parity[a[i].S] = 1;//even place
                }
        }

        for(i = 0;i < n;i += 2){
                if(parity[i] == 0) ans++;
        }
        cout << ans << ln;

}

int main(){
        fio;
        //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
//////////////////////////////////////////////////////
        ll tt = 1;
        //cin >> tt;
        //ll t = tt;
        cout<<fixed<<setprecision(10);
        while(tt--){
                //cout << "Case #" << t - tt << ": ";
                go1();
        }
//////////////////////////////////////////////////////
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        long double time_spent = (chrono::duration_cast<chrono::duration<long double> >(end-start)).count();
        //double time_taken = time_spent / double(CLOCKS_PER_SEC);
        cerr<<time_spent<<'\n';
        return 0;
}
