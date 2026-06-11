#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long x;
    cin>>x;
    long long ans=0;
    ans=x/11;
    ans*=2;
    long long r=x%11;
    if(r>6){
        ans+=2;
    }else if(r>0){
        ans++;
    }else{

    }
    cout << ans << endl;
    return 0;
}