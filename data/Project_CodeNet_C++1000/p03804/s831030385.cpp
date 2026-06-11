#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<string> a(n); rep(i,n) cin >> a[i];
    vector<string> b(m); rep(i,m) cin >> b[i];

    if(n-m == 0 && a == b){
        put("Yes");
        return 0;
    }

    for(int i = 0; i < n-m; i++){
        ll flag;
        auto index = a[i].find(b[0]);
        if(index != string::npos) flag = 1;
        else flag = 0;
        //put(index);
        for(int y = 1; y < m; y++){
            for(int x = 0; x < m; x++){
                if(a[i+y][index+x] != b[y][x]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            put("Yes");
            return 0;
        }
    }
    put("No");
}