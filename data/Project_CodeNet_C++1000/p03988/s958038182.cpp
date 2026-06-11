#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
    int N;
    bool ans=true;
    cin >> N;
    int dis[N]={};
    rep(i,N){
        int x; cin >> x;
        dis[x]++;
    }
    int remain=N,p=N-1;
    while(true){
        if(dis[p]==1) ans=false;
        else if(dis[p]>=2){
            dis[p]-=2;
            remain-=2;
            break;
        }
        p--;
    }
    int L=p-1,able;
    while(L>0){
        p--;
        if(p==0 && L>0){
            ans=false;
            break;
        }
        int minus=min(L,2);
        if(dis[p]<minus) ans=false;
        dis[p]-=minus;
        L-=minus;
        remain-=minus;
        able=p;
    }
    able++;
    rep(i,N) if(i<able && dis[i]>0) ans=false;
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}