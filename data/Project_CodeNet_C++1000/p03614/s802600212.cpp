#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;

signed main(){
    int n;
    cin >> n;
    vint s(n);
    rep(i,n) cin >> s[i];
    bool flag = false;
    int ans = 0;
    rep(i,n){
        if(s[i] == i + 1){
            ans++;
            i++;
        }
    }
    cout << ans << endl;
} 