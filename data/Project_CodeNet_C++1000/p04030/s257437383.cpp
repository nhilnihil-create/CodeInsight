#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    string s;
    cin >> s;
    string ans;

    ll n = s.size();
    rep(i, n){
        if (s[i] == '0'){
            ans.push_back('0');
        }else if(s[i] == '1'){
            ans.push_back('1');
        }else if(s[i] == 'B'){
            if (ans.size() > 0){
                ans.pop_back();
            }
        }
    }

    cout << ans << endl;


    return 0;
}
