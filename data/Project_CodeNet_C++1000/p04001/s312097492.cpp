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
    int n = s.size() - 1;

    ll ans = 0;
    for(int bit = 0; bit < (1 << n); bit++) {
        int t = 0, k = 1;
        vector<string> A;
        rep(i, n) {
            if(bit >> i & 1) {
                A.push_back(s.substr(t, k));
                t += k;
                k = 1;
            } else k++;
        } 
        A.push_back(s.substr(t, k));
        rep(j, A.size()) {
            ans += stoll(A[j]);
        }
    }
    cout << ans << endl;
  
    return 0;
}