//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) {
        cout << "YES";
    }
    else cout << "NO";
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}