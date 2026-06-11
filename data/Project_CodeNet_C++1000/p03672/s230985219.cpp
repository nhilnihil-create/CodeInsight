#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

bool f(string& s, ll e){
    rep(i, e/2){
        if (s[i] != s[i+e/2]){
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    ll i = s.size();
    if (s.size() % 2 ==0){
        i -= 2;
    }else
    {
        i -= 1;
    }
    
    for(;i>0;i-=2){
        if (f(s, i)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
