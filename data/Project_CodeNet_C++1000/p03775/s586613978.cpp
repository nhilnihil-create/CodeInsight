#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;

    int ans=1e9;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            string s=to_string(i);
            string t=to_string(n/i);
            ans=min(ans,max((int)s.length(),(int)t.length()));
        }
    }
    cout<<ans<<endl;
}