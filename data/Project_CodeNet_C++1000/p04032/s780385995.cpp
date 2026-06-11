#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    if(s.size() == 2){
        if(s[0] == s[1]){
            cout << "1 2\n";
        }
        else {
            cout << "-1 -1\n";
        }
        return 0;
    }

    rep(i, s.size()-2){
        if(s[i] == s[i+1] || s[i] == s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0; 
        }
    }

    cout << "-1 -1\n";
}