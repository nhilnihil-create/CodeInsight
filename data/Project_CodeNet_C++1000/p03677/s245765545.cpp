#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
//template end



int main(){
    int n,m; scanf("%d%d",&n,&m);
    int a[100010]={};
    rep(i,0,n)scanf("%d",&a[i]),a[i];
    ll imos[200010]={},ans=0;
    rep(i,0,n-1){
        int s=a[i],t=a[i+1]; if(s>t)t+=m;
        int d=t-s; ans+=d;
        imos[s+1]++; imos[t]-=d; imos[t+1]+=d-1;
    }
    rep(rot,0,2)rep(i,0,2*m)imos[i+1]+=imos[i];
    ll dec=0;
    rep(i,0,m)chmax(dec,imos[i]+imos[m+i]);
    printf("%lld\n",ans-dec);
    return 0;
}