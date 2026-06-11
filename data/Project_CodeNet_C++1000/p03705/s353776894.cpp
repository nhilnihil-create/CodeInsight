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
    ll n,a,b;
    cin>>n>>a>>b;
    if(b<a){
        cout<<0<<endl;
        return 0;
    }
    if(n==1){
        if(a!=b){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
        return 0;
    }
    cout<<(b-a)*(n-2)+1<<endl;
    
}
