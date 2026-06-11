#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int W,a,b;
    cin>>W>>a>>b;
    int rr=a,rl=a+W,br=b,bl=b+W;
    int ans;
    if(rl<br){
        ans=br-rl;
    }else if(bl<rr){
        ans=rr-bl;
    }else{
        ans=0;
    }
    cout << ans << endl;
    return 0;
}