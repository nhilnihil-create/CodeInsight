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

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const string& a, const string& b) {
    return (a + b) < (b + a);
}

void solve(){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int up1 = y2 - y1;
    int r1 = x2 - x1;
    for(int i = 1; i <= up1; i++)
        cout << 'U';
    for(int i = 1; i <= r1; i++)
        cout << 'R';
    for(int i = 1; i <= up1; i++)
        cout << 'D';
    for(int i = 1; i <= r1; i++)
        cout << 'L';
    cout << 'L';
    for(int i = 1; i <= up1 + 1; i++)
        cout << 'U';
    for(int i = 1; i <= r1 + 1; i++)
        cout << 'R';
    cout << "DR";
    for(int i = 1; i <= up1 + 1; i++)
        cout << 'D';
    for(int i = 1; i <= r1 + 1; i++)
        cout << 'L';
    cout << 'U';

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
