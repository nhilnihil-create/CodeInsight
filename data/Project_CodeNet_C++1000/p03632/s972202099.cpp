#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int ans;
int main(void){
    int a,b,c,d; cin>>a>>b>>c>>d;
    for(int i=0;i<=100;i++){
        if(a<=i&&i<=b&&c<=i&&i<=d){
            ans++;
        }
    }
    cout<<max(0,ans-1)<<endl;
    
}
