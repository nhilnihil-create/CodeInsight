#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    string s;int k;cin>>s>>k;
    REP(i,s.size()){
        if('z'+1-s[i]<=k&&s[i]!='a'){
            k-='z'+1-s[i];
            s[i]='a';
        }
    }
    s[s.size()-1]+=k%26;
    cout<<s<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}