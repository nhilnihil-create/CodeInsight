#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    long long A,B;
    cin>>N>>A>>B;
    long long ans=0;
    vector<long long> X(N);
    rep(i,N){
        cin>>X.at(i);
    }
    long long now=X.at(0);
    rep2(i,1,N){
        ans+=min(B,A*(X.at(i)-now));
        now=X.at(i);
    }
    cout << ans << endl;
    return 0;
}