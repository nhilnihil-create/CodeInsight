#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
string s,t;
int main(void){
    cin>>n>>s>>t;
    for(int i=n;i>=0;i--){
        bool x=true;
        for(int j=0;j<i;j++){
            if(s[n-i+j]==t[j]){
                
            }else{
                x=false;
            }
        }
        if(x){
            cout<<n+n-i<<endl;
            return 0;
        }
    }

}

