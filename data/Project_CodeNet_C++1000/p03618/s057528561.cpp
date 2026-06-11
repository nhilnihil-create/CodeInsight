#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int> 
#define F first 
#define S second 
#define int long long
typedef long long ll;

const int maxn = 3e5+10;
const int mod = 1e9+7;
//const int inf = 2e18+10;

int n, m, k;
int cnt[26];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; cin>> s; 
    for(auto c : s) cnt[c-'a']++;
    ll ans = 1;
    for(int i = 0; i < 26; i++)
        for(int j = i+1; j < 26; j++)   
            ans += cnt[i] * cnt[j];
    cout<< ans;
}
