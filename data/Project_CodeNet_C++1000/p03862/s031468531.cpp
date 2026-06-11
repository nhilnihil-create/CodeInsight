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

const int INF = 1e9 + 5;
const long long MAXN=2e5 + 5;;

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const string& a, const string& b) {
	return (a + b) < (b + a);
}

vector<int> Reversed(const vector<int>& s){
   vector<int> d = s;
   reverse(all(d));
   return d;
}

void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll sum = 0;
    if(a[0] > x){
        sum = a[0] - x;
        a[0] = x;
    }
    for(int i = 0; i < n-1; i++){
        if(a[i+1] + a[i] > x){
            sum += (a[i+1] + a[i]) - x;
            a[i+1] = a[i+1] - ((a[i+1] + a[i]) - x);
        }
    }
    cout << sum;
}


int main(){
    //freopen("slalom.in","r",stdin);
    //freopen("slalom.out","w",stdout);
    //faster();
    int n = 1;
    //cin >> n;
    while(n--){
        solve();
        cout << endl;
    }
    //fclose(stdout);
}
