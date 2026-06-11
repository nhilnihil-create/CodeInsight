#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=3;
    if(a==b&&a!=c)ans=2;
    else if(a==b&&a==c)ans=1;
    else if(a==c)ans=2;
    else if(a!=c&&b==c)ans=2;
    cout << ans << endl;
    
    return 0;
}