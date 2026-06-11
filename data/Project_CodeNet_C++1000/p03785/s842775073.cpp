#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,c,k;cin>>n>>c>>k;
    int tmp=0,lim=0,res=0;
    vector<int> T(n);
    rep(i,n) cin>>T[i];
    sort(T.begin(),T.end());
    lim=T[0];
    rep(i,n){
        int t=T[i];
        if(t>lim+k){
            lim=t;
            tmp=1;
            res++;
        }else if(tmp==c){
            lim=t;
            tmp=1;
            res++;
        }else{
            tmp++;
        }
    }
    if(tmp>0)res++;
    cout<<res<<endl;
}
