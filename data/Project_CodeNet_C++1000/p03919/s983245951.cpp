#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int H,W;cin>>H>>W;
    rep(i,H)rep(j,W){
        string s;
        cin>>s;
        if(s=="snuke"){
            cout<<(char)(j+'A')<<i+1<<endl;
        }
    }
}
