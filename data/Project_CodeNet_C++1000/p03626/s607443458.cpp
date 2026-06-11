#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF =1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define pb push_back
int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi v;
    rep(i,n){
        if(s[i]==t[i]){
            v.push_back(1);
        }else{
            v.push_back(0);
            i++;
        }
    }
    lint ans;
    if (v[0] == 1)
    {
        ans = 3;
    }else{
        ans = 6;
    }
    rep(i,v.size()-1){
        if(v[i]==0 && v[i+1]==0){
            ans *= 3;
            ans %= MOD;
        }
        else if (v[i] == 0 && v[i + 1] == 1)
        {
            ans *= 1;
            ans %= MOD;
        }else if(v[i]==1 && v[i+1]==0){
            ans *= 2;
            ans %= MOD;
        }else{
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}