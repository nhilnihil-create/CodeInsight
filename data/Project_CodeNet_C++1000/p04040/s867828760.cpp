#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e6+6,P=1e9+7;
int f[N],iv[N];
int C(int n,int m){ return (ll)f[n]*iv[m]%P*iv[n-m]%P; }
int path(int n,int m){ return C((n-1)+(m-1),n-1); }
int main(){
    int n,m,a,b; cin>>n>>m>>a>>b;
    int t=2*max(n,m); f[0]=1,iv[0]=iv[1]=1;
    rep(i,1,t) f[i]=(ll)f[i-1]*i%P;
    rep(i,2,t) iv[i]=(ll)iv[P%i]*(P-P/i)%P;
    rep(i,2,t) iv[i]=(ll)iv[i-1]*iv[i]%P;
    int s=(ll)path(n-a+1,b)*path(a,m-b+1)%P;
    rep(i,n-a+2,n)
        s=(s+(ll)path(i,b-1)*path(n-i+1,m-b+1))%P;
    cout<<(path(n,m)-s+P)%P<<endl;
    return 0;
}
