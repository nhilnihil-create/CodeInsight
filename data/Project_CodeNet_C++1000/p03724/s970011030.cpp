#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int main(){
    int n,m;cin >> n >> m;
    vector<int> cnt(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        --a;--b;
        cnt[a] = 1-cnt[a];
        cnt[b] = 1-cnt[b];
    }

    rep(i,n) {
        if(cnt[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
}