#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string O,E;
    cin>>O>>E;
    string ans="";
    if(O.size()>E.size()){
        rep(i,E.size()){
            ans=ans+O.at(i);
            ans=ans+E.at(i);
        }
        ans=ans+O.at(O.size()-1);
    }else{
        rep(i,E.size()){
            ans=ans+O.at(i);
            ans=ans+E.at(i);
        }        
    }
    cout << ans << endl;
    return 0;
}