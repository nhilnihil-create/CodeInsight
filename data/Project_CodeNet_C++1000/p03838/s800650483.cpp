#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int x,y;
    cin>>x>>y;
    int ans;
    if(x<y)ans=min(y-x,abs(y+x)+1);
    else ans=min(1+x-y,abs(x+y))+1;
    cout<<ans<<endl;
}