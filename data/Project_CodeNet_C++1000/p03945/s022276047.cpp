#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string S;
    cin>>S;
    int ans=0;
    rep(i,S.size()-1){
        if(S.at(i)!=S.at(i+1)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}