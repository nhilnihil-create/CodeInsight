#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    vector<bool> b(4,false);
    for(char c:s){
        if(c=='N')b[0]=true;
        if(c=='W')b[1]=true;
        if(c=='S')b[2]=true;
        if(c=='E')b[3]=true;
    }
    if(b[0]^b[2]||b[1]^b[3])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}