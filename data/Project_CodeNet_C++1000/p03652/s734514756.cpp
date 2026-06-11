#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = 998244353;
const long long INF_LL = 1e18+3; const int INF_int = 1e9+3;
#define ll long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto itr = a.begin();itr!=a.end();itr++) cout << *itr << " ";cout << endl;
int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    rep(i,n)rep(j,m) cin >> a[i][j];
    rep(i,n) rep(j,m) a[i][j]--;
    int ans = n;
    vector<int> nowselect(n);
    vector<int> nowpeople(m);
    rep(i,n) nowselect[i]=0;
    set<int> sports;
    rep(i,m) sports.insert(i);
    while(!sports.empty()){
        int maxsports = -1;
        int maxpeople = -1;
        fill(All(nowpeople),0);
        rep(i,n) nowpeople[a[i][nowselect[i]]]++;
        rep(i,m){
            if(maxpeople<nowpeople[i]){
                maxpeople = nowpeople[i];
                maxsports = i;                
            }
        }
        ans = min(ans,maxpeople);
        sports.erase(maxsports);
        if(sports.empty()) break;
        rep(i,n){
            if(a[i][nowselect[i]]==maxsports){
                int now = nowselect[i];
                while(sports.count(a[i][now])==0) now++;
                nowselect[i]=now;
            }
        }
    }
    cout << ans << endl;
}