#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(int i=s.size()-1; i>0; i--){
        for(int j=1; j<=i/2; j++){
            if(i%j || (i/j)%2) continue;
            bool ok=true;
            for(int k=0; k+j<=i; k+=j){
                if(s.substr(0,j)!=s.substr(k,j)) ok=false;
            }
            if(ok){
                ans=max(ans,i);
            }
        }
    }
    cout<<ans<<endl;
}