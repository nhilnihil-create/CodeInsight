#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++) 
#define rrep(i,n) for(int i = 1; i <= (int)(n); i++) 
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

//const ll mod = 1000000007;
//const ll INF = mod * mod;
//const double pi = 3.14159265358979;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int counter = 0;
    rep(i,n) {
        if(a[i] % 2 == 1) counter++;
    }
    if(counter % 2 == 0) puts("YES");
    else puts("NO");
}