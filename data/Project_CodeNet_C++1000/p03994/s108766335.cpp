#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    for(i = 0;i < n;++i){
        ll tmp = (26 - (s.at(i) - 'a'))%26;
        if(tmp <= k){
            k -= tmp;
            s.at(i) = 'a';
        }
    }
    k %= 26;
    s.back() += k;
    cout << s << endl;

    return 0;
}