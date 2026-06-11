#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool flag=true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]==b[k][l]) continue;
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}