#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

string s="RYGB";

signed main(){
    int H,W,d;
    cin>>H>>W>>d;

    rep(i,H){
        rep(j,W){
            int y=i+j;
            int x=i-j;

            int c=(y+114514*d)%(2*d)/d*2+(x+114514*d)%(2*d)/d;
            cout<<s[c];
        }
        cout<<endl;
    }
    return 0;
}
