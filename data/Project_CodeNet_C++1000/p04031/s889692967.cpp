#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = 1; i <= (int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

//const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) {
        cin >> a[i];
    }
    int ans = 1000000;
    sort(all(a));
    for(int i = a[0]; i <= a[n-1]; i++) {
        int counter = 0;
        rep(j,n) {
            int dif = abs(a[j] - i);
            dif *= dif;
            counter += dif;
        }
        ans = min(ans,counter);
    }
    cout << ans << endl;
}