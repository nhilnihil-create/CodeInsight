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
const int MAXN = 3e6 + 123;

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
    int n,k;
    cin >> n >> k;
    ull ans = pow(k-1,n-1);
    ull cnt = ans * k;
    cout << cnt;
}
int main(){
    //freopen("lepus.in","r",stdin);
   // freopen("lepus.out","w",stdout);
    //faster();
    int n=1;
    //cin>>n;
    while(n--){
        solve();
        //cout << endl;
    }
    //fclose(stdout);
}
