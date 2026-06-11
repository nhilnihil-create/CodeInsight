#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int ww,hh,n;
    cin >> ww >> hh >>n;
    vector<int> W(ww+1);
    vector<int> H(hh+1);

    rep(i,ww+1)W[i]=0;

    rep(i,hh+1)H[i]=0;

    int xf=0,xl=ww;
    int yf=0,yl=hh;
    rep(i,n)
    {
        int x,y,a;
        cin>>x >> y >>a;
        if(a==1){
            xf = max(xf,x);
            
        }else if(a==2){
            xl = min(xl,x);
            
        }else if(a==3){
            yf = max(yf,y);
         
        }else{
            yl = min(yl,y);
        }
    }
    if( (xl-xf)<=0||0>=(yl-yf)){
        cout<<0<<endl;
        return 0;
    }
    int ans = (xl-xf)*(yl-yf);
    cout<<ans<<endl;
    //cout<<W.siz+1)e()<<endl;
    return 0;

}
