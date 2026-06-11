#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
const ll mod=1e+9+7;
int main(void){
    int n;cin>>n;
    string s1,s2;cin>>s1>>s2;
    ll res=1;
    int pt=1;//前のパターンを保存
    rep(i,n){
        if(i==0){
            if(s1[i]!=s2[i]){
                res*=6;
                res%=mod;
                i++;
                continue;
            }else{
                res*=3;
                res%=mod;
                pt=2;
                continue;
            }
        }
        if(s1[i]!=s2[i]){
            if(pt==1){
                res*=3;
            }else{
                pt=1;
                res*=2;
            }
            res%=mod;
            i++;
        }else{
            if(pt==1){
                pt=2;
            }else{
                res*=2;
            }
            res%=mod;
        }
    }
    cout<<res<<endl;
}