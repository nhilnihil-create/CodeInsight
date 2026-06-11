#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a[3];
int main(void){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int ans=3;
    if(a[0]==a[1]&&a[1]==a[2]){
        ans=1;
    }else if(a[0]==a[1]){
        ans=2;
    }else if(a[1]==a[2]){
        ans=2;
    }
    cout<<ans<<endl;
    
}
