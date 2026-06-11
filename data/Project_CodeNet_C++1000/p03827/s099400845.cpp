#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,x,ans;
string s;
int main(void){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            x++;
            ans=max(ans,x);
        }else{
            x--;
        }
    }
    cout<<ans<<endl;
    
}
