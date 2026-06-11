#include <iostream>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    string t = "CODEFESTIVAL2016";
    ll ans = 0;
    for(ll i = 0; i < s.size(); ++i){
        ans += (s.at(i) != t.at(i));
    }
    cout << ans << endl;
    return 0;
}
