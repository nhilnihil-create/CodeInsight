#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;


int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    rep(i,n) {
        cin >> s[i];
        ans += s[i];
    }
    sort(ALL(s));
    if(ans % 10 != 0){
        cout << ans << endl;
        return 0;
    }
    rep(i,n){
        if(s[i] % 10 == 0) continue;
        else{
            cout << ans - s[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
}