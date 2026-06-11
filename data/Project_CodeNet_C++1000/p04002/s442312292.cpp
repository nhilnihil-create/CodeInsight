#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct hoge{ll a,b;};
bool comp(hoge xx,hoge y){
    if(xx.a<y.a)return true;
    if(xx.a==y.a){
        return xx.b<y.b;
    }
    return false;
}

hoge x[100010];
ll h,w,n;

bool find(ll c,ll d){
    hoge hog;hog.a=c;hog.b=d;
    ll L=0;
    ll R=n-1;
    ll mid;
    while(R-L>1){
        mid=(R+L)/2;
        if(comp(hog,x[mid])){
            R=mid;
        }else{
            L=mid;
        }
    }
    if(hog.a==x[L].a && hog.b==x[L].b)return true;
    if(hog.a==x[R].a && hog.b==x[R].b)return true;
    if(R<n-1)if(hog.a==x[R+1].a && hog.b==x[R+1].b)return true;
    return false;
    
}

int main(){
    cin>>h>>w>>n;
    rep(i,0,n-1)cin>>x[i].a>>x[i].b;
    sort(x,x+n,comp);
    bool bol[5][5];
    ll ans[10];rep(i,0,9)ans[i]=0;
    ll counter;
    if(n==0){
        cout<<(h-2)*(w-2)<<endl;
        rep(i,1,9){
            cout<<0<<endl;
        }
        return 0;
    }
    rep(i,0,n-1){
        rep(sx,-2,2)rep(sy,-2,2){
            if(x[i].a+sx>=1 && x[i].a+sx<=h && x[i].b+sy>=1 && x[i].b+sy<=w){
                bol[sx+2][sy+2]=find(x[i].a+sx,x[i].b+sy);
            }else{
                bol[sx+2][sy+2]=false;
            }
        }
        rep(sx,-1,1)rep(sy,-1,1){
            if(x[i].a+sx-1>=1 && x[i].a+sx+1<=h && x[i].b+sy-1>=1 && x[i].b+sy+1<=w){
                counter=0;
                rep(tx,-1,1)rep(ty,-1,1){
                    if(bol[sx+tx+2][sy+ty+2])counter++;
                }
                ans[counter]++;
            }
        }
    }
    ll sum=0;
    rep(i,1,9){
        ans[i]/=i;
        sum+=ans[i];
    }
    ans[0]=(h-2)*(w-2)-sum;
    rep(i,0,9){
        cout<<ans[i]<<endl;
    }
    /*
    rep(i,1,h){
        rep(j,1,w){
            cout<<find(i,j)<<' ';
        }
        cout<<endl;
    }*/
    
    
    return 0;
}
