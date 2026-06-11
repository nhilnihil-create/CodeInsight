#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];

    int ans = 0;
    int light = 1;
    rep(i,n){
        light = a[light];
        ans++;
        if(light == 2) {
            break;
        }
        
    }

    if(light == 2) cout << ans << endl;
    else cout << -1 <<endl;

}