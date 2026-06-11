#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int now = 0;
    int ans = 0;
    while(now < n){
        if(p[now] != now + 1){
            now++;
        }
        else{
            ans++;
            now += 2;
        }
    }
    cout << ans << endl;
}