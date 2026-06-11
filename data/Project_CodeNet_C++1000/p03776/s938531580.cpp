#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)

//library----------------------------------------------

#define NMAX 50
 
ll comb(int n,int k){
    ll ans = 1;
    Rep(i,1,k+1){
        ans*=n-i+1;
        ans/=i;
    }
    return ans;
}

int main(){
    int N,A,B; cin>>N>>A>>B;
    ll v[NMAX];
    rep(i,N) cin>>v[i];
    sort(v,v+N,greater<ll>());

    double ave = 0.0;
    rep(i,A) ave += v[i];
    ave /= A;
    printf("%.10f\n",ave);

    ll ans = 0LL;
    int x=A-1,y=A-1;
    while(v[x-1]==v[x]&&x-1>=0) x--;
    while(v[y]==v[y+1]&&y+1<N) y++;    
    for(int i=A; i<=(x?A:B); i++){
        ans += comb(y-x+1,i-x);
    }
    printf("%lld",ans);
    return 0;
}