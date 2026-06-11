#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector <int> vi;
const int MOD = 1e9 + 7;

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    if(a.back() == b[0] && b.back() == c[0]) cout << "YES";
    else cout << "NO";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}