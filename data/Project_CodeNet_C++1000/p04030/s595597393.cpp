#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s;
    cin >> s;
    string ans;
    rep(i,s.size()){
        if(s[i] == '0') ans+="0";
        else if(s[i] == '1') ans+="1";
        else if(ans!="") ans.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}