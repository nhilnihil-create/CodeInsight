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
    int a;
    cin >> a;
    if(a >= 1200) cout << "ARC";
    else cout << "ABC";
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
