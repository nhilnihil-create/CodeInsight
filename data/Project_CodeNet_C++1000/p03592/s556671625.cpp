//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if((n-i)*j+i*(m-j)==k){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    
}
