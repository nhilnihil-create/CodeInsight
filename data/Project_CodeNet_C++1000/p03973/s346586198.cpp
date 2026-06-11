#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll INF=1000000010;
const ll MOD=1000000007;
const ll LINF=4000000000000000000;
const long double EPS=1e-9;
typedef pair<int,int> P;
int main(){
    int n;cin>>n;
    ll ans=0;
    int s=2;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(i==0){
            ans+=a-1;
        }else if(a==s){
            s++;
        }else{
            ans+=(a-1)/s;
        }
    }
    cout<<ans<<endl;
}