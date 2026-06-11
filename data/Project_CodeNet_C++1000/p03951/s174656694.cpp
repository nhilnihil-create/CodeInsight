#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    char s[n],t[n];
    rep(i,n)cin >> s[i];
    rep(i,n)cin >> t[i];
    int ans = 2*n;
    for(int i = 1;i <= n;i++){
        bool ok = true;
        rep(j,i){
            if(s[n-i+j] != t[j]){
                ok = false;
                //cout << i << ' ' << j << ' ' << s[n-1-j] << ' ' << t[j] << endl;
            }
        }
        if(ok)ans = n*2-i;
    }
    cout << ans << endl;
    return 0;
}