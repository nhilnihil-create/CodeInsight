#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    vector<bool> D(1000, false) ;
    rep(i, s.size()) {
        D[s[i]] = true;
    }
    if(D['N'] != D['S'] || D['W'] != D['E']) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}