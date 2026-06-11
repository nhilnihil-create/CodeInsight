#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);


int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    int ans = 0;
    rep(i,101){
        if(a <= i && i < b){
            if(c <= i && i < d){
                ans ++;
            }
        }
    }
    cout << ans << endl;
}