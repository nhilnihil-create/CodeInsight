#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n);
    rep(i,m){
        int a,b;
        cin >> a >> b ;
        --a;--b;
        cnt[a] ++;
        cnt[b] ++;
    }
    rep(i,n){
        if(cnt[i]%2==1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}