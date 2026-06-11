#include<bits/stdc++.h>
 
using namespace std;
long long mod=1e9+7;
long long INF=1e7;
double EPS = 1e-12;
const long long lim = 1e6+100;
typedef long long int lld;
typedef long long ll;

#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); i--)
#define mset(a, v) memset(a, v, sizeof(a))
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
 
 
#define popcount __builtin_popcountll
 
ll powP(ll x, ll y) {
    ll ans = 1, po = x % mod;
    while(y > 0) {
        if(y & 1) ans = ans * po % mod;
        y >>= 1; po = po * po % mod;
    }
    return ans;
}

ll findGcd(ll a, ll b){
    while(a != 0) { ll temp = b % a; b = a; a = temp; }
    return b;
}

set<ll> S[lim];
ll Array[lim], Prime[lim];



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    lld T,i,p,j,l,e,r,b,c,k,m,q,a,d,w,x,y,u,v,z,t,curr,prev,sum=0,val,countA=0,indicator=0,pos,h,minA,maxA,type,n,ans=0,left,right;
    string A,B;
    A = "Yes", B="No";
    cin>>n>>l;
    rep(i,1,n) cin>>Array[i];
    indicator=0;
    rep(i,1,n-1) {
        if(Array[i]+Array[i+1]>=l) indicator=1, val=i;
    }

    if(indicator==0) cout<<"Impossible"<<endl;
    else {
        cout<<"Possible"<<endl;
        rep(j,1,val-1) cout<<j<<endl;

        repD(j,n-1,val) cout<<j<<endl;
    }

    return 0;
}
    