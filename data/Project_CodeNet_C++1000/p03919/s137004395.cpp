#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
int h,w;
string s[30][30];
signed main(){
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>s[i][j];
            if(s[i][j]=="snuke"){
                char c='A'+j;
                cout<<c<<i+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}