#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

int main(){
    int N,K; scanf("%d %d",&N,&K);
    vec A(N),S(N+1),L(N+1),R(N+1);S[0]=L[0]=R[0]=0;
    rep(i,N){
        scanf("%lld",&A[i]);
        S[i+1]=S[i]+A[i];
        L[i+1]=L[i];
        if(A[i]>0) L[i+1]+=A[i];
    }
    rep(i,N){
        R[i+1]=R[i];
        if(A[N-1-i]>0) R[i+1]+=A[N-1-i];
    }
    ll ans=0;
    rep(i,N-K+1){
        ll x=max((ll)0,S[i+K]-S[i])+L[i]+R[N-i-K];
        ans=max(ans,x);
    }
    printf("%lld\n",ans);
    return 0;
}