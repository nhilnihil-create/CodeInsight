#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector< ll >cnt(26,0);
    string s;cin>>s;
    ll ans = 1 , n=s.size();
    for(ll i=0;i<n;i++)
        ans+=i-cnt[s[i]-'a'] , cnt[s[i]-'a']++;
    cout<<ans;
}



