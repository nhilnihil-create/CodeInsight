#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ll long long
const int INF = 1e9 + 7;

using namespace std;

int main(){
    cin.tie(0), ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> pattern;
    REP(i,30) if(k >> i & 1) pattern.push_back(i);

    vector<ll> ans(pattern.size(),0);
    ll ansk=0;
    REP(i,n){
        int a,b;
        cin >> a >> b;
        if(k == (k|a)){
            ansk += b;
        }
        REP(j,pattern.size()){
            if(((k>>pattern[j])-1)==(((k>>pattern[j])-1)|(a>>pattern[j]))){
                ans[j]+=b;
            }
        }
    }

    ans.push_back(ansk);
    cout << *max_element(ans.begin(),ans.end()) << endl;
    return 0;
}
