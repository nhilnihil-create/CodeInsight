#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length()-1;
    ll ans = 0;
    ll tmp = 0;
    ll res = 0;
    rep(i,1<<n){
        tmp = 0;
        rep(j,s.length()){
            if(j){
                if(i>>j-1&1){
                    tmp += ans;
                    ans = 0;
                    ans += (s[j]-'0');
                }else{
                    ans = ans*10+(s[j]-'0');
                }
            }else{
                ans += (s[j]-'0');
            }
        }
        ans += tmp;
        res += ans;
        ans = 0;
    }
    cout << res << endl;

    cout << endl;
    return 0;
}
