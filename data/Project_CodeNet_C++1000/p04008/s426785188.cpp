#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 1e18;
long long int mod = 1000000007;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "RULD";
//↓,→,↑,←

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

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
        swap(number1 , number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1 , number1);
    }
}

ll i,j,k,ii,jj,n,m,a,b,c,d,e,g,h,w,num,sum,ans;
ll x[500005];//y[500005],z[500005];
bool ok[500005];
//ll l[500005],r[500005];
int dp[100005][505];
//char s[500005],t[500005];

ll dfs(ll v,ll p,ll cost){
    ll num = -INF;
    for(int i=0;i<G[v].size();i++){
        
        num = max(num,dfs(G[v][i],v,cost));
    }
    if(num == -INF){
        return 1;
    }
    num ++;
    if(num == k){
        if(ok[v]){
            return 0;
        }
        ans++;
       // p(v);
        return -INF;
    }else{
        return num;
    }
}



int main(){
    cin >> n >> k;
    if(k >= n){
        cin >> a;
        if(a == 1){
            p(0);
        }else{
            p(1);
        }
        return 0;
    }else if(k == 1){
        for(i =0;i<n;i++){
            cin >> a;
            if(a != 1)ans++;
        }
        p(ans);
    }else{
        for(i=0;i<n;i++){
            cin >> x[i];
        }
        if(x[0] != 1){
            ans++;
            x[0] = 1;
        }
        for(i=1;i<n;i++){
            G[x[i]].pb(i+1);
            if(x[i] == 1){
                ok[i+1] = 1;
            }
        }
        ok[1] = 1;
        a = dfs(1,-1,0);
        p(ans);
    }
    return 0;
}




