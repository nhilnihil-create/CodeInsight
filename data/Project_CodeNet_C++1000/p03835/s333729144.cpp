#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題

int main() {
    int k,s;
    cin>>k>>s;
    int ans=0;
    rep(i,k+1){
        rep(j,k+1){
            int x=s-i-j;
            if(0<=x&&x<=k) ans++;
    
        }
    }
    cout<<ans<<endl;
    return 0;
}
