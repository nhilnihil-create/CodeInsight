//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll H,W,h,w,sum; cin>>H>>W>>h>>w;
    if(h==1 && w==1){
        printf("No\n");
        return 0;
    }
    ll d=999999999LL/(h*w-1);
    vector<vector<ll>> ans(H,vector<ll>(W,d));
    sum=H*W*d;
    for(int i=h-1;i<H;i+=h)for(int j=w-1;j<W;j+=w){
        sum-=d+(h*w-1)*d+1; ans[i][j]=-(h*w-1)*d-1;
    }
    if(sum>0){
        printf("Yes\n");
        rep(i,H){
            rep(j,W) printf("%lld ",ans[i][j]);
            printf("\n");
        }
    }
    else printf("No\n");
}
