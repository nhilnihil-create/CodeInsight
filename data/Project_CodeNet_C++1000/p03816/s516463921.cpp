// AtCoder template
// 見た奴全員saba!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    map<int,int> m;
    int cnt = 0;
    rep(i,n){
        if(m[a[i]] == 0) cnt++;
        m[a[i]]++;
    }
    int evencnt = 0;
    for(auto i:m){
        if(i.second % 2 == 0) evencnt++;
    }
    if(evencnt % 2 == 0) cout << cnt << endl;
    else cout << cnt-1 << endl;
}