#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> x(m,vector<int>());
    rep(i,n){
        int y;
        cin >> y;
        x[y%m].push_back(y);
    }
    vector<int> cnt(m);
    rep(i,m){
        sort(x[i].begin(),x[i].end());
        int c = 0;
        int now = -1;
        int se = 0;
        rep(j,x[i].size()){
            if(now==x[i][j]){
                ++se;
            }
            else{
                c += se/2;
                se=1;
                now=x[i][j];
            }
        }
        c+=se/2;
        cnt[i]=c;
    }
    /*
    rep(i,m){
        cout << cnt[i] << " ";
        rep(j,x[i].size()){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    vector<int> use(m,0);
    int ans = 0;
    ans += (int)(x[0].size())/2;
    for(int i=1;2*i<=m;++i){
        if(2*i==m){
            ans+=(int)(x[i].size())/2;
            continue;
        }
        ans += min((int)x[i].size(),(int)(x[m-i].size()));
        use[i] = min((int)x[i].size(),(int)(x[m-i].size()));
        ans += min(((int)(x[i].size())-use[i])/2,cnt[i]);
        ans += min(((int)(x[m-i].size())-use[i])/2,cnt[m-i]);
    }
    cout << ans << endl;
    return 0;
}