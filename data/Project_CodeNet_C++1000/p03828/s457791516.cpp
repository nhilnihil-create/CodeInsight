#include <bits/stdc++.h>

using namespace std;

#define vit vector<int>::iterator
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fr first
#define sc second
#define skip continue
#define PI 3.14159265

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 3e5 + 3;
const int  M   =   1e9+7;

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const string& a, const string& b) {
    return (a + b) < (b + a);
}

void solve(){

    ll n, m, i, j, k, x;

    cin >> n;
    map<ll, ll> a;
    for(k = 2; k <= n; ++k)
    {
        ll cnt = 0;
        ll num = k;
        while(num % 2 == 0) {
            ++cnt;
            num /= 2;
        }
        if(cnt) a[2] += cnt;
        for(i = 3; sqrt(i) <= num; i += 2) {
            if(num % i == 0) {
                cnt = 0;
                while(num % i == 0) {
                    ++cnt;
                    num /= i;
                }
                a[i] += cnt;
            }
        }
        if(num > 1) a[num]++;
    }

    ll tot = 1;
    for(auto t : a)
    {
        tot *= (t.second + 1);
        tot %= M;
    }
    cout << tot << endl;
}


int main(){
    
    int n = 1;
   
    while(n--){
        solve();
        cout << endl;
    }
  
}
