#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[500005];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←
 
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
 
 
ll mod = 1000000007;
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
 
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}

 
//ll fact[800005],rfact[800005];
/*
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[800000] = rui(fact[800000],mod - 2);
    for(ll i=800000; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/
 
ll n,m,num,sum,ans,a,b,c,e,g,h,w,i,j,k,q;
//ll x[500005],y[500005],z[500005];
ll vertex[500005],dist[500005],co[500005];
ll color_table[500005][12];
bool kakutei[500005];
bool dame;

void init(){

    return ;
}

void dfs(ll v,ll d,ll color,ll parent){
    if(d < 0)return;
    if(color_table[v][d] == 0){
        for(int k=d;k>=0;k--){
            if(color_table[v][k] == 0)color_table[v][k] = color;
        }
    }else{
        return;
    }
    for(int i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == parent)continue;
        dfs(nv,d-1,color,v);
    }
    return;
}

void paint(ll v,ll d,ll color){
    dfs(v,d,color,-1);
}

int main(){
    cin >> n >> m;
    init();
    for(i=0;i<m;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    cin >> k;
    for(i=0;i<k;i++){
        cin >> vertex[i] >> dist[i] >> co[i];
    }
    for(int i=k-1;i>=0;i--){
        paint(vertex[i],dist[i],co[i]);
    }
    for(i=1;i<=n;i++){
        p(color_table[i][0]);
    }

    
    return 0;
}










