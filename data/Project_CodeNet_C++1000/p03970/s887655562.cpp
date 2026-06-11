#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s,t;
int ans;
int main(void){
    s="CODEFESTIVAL2016";
    cin>>t;
    for(int i=0;i<16;i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
