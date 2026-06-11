#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
#define MOD 1000000007
#define int long long

signed main(){
    int h,w;cin>>h>>w;
    rep(i,h)rep(j,w){
        string s;cin>>s;
        if(s=="snuke"){
            cout<<(char)('A'+j)<<i+1<<endl;
        }
    }
}