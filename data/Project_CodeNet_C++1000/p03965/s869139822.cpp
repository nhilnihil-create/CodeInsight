#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
int main(void){
    string s;
    cin>>s;
    ll n=s.size();
    ll p=0,g=0;
    for(int i=0;i<n;i++){
        if(s[i]=='p') p++;
        else g++;
    }
    cout<<n/2-p<<endl;
}