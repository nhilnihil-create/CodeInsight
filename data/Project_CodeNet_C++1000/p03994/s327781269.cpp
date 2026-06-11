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
    int n;
    cin >> s >> n;
    rep(i, s.size()){
        if(n == 0) break;
        if(i == s.size() - 1) {
            n %= 26;
            while(n != 0) {
                if(s[i] == 'z') {
                    s[i] = 'a';
                    n--;
                } else {
                    s[i] += 1;
                    n--;
                }
            }
        }
        if('z' - s[i] < n) {
            if(s[i] == 'a') continue;
            int a = 'z' + 1 - s[i];
            s[i] = 'a';
            n -= a;
        }
    }

    cout << s << endl;

    return 0;
}