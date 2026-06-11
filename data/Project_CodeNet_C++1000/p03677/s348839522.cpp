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


ll i,j,k,ii,jj,n,m;
ll a,b,c,d,e,g,h,r,num,sum,ans;
ll x[500005],y[500005],z[500005];
bool dame;

int main(){
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> x[i];
    }
    for(i=1;i<n;i++){
        a = x[i] - x[i-1];
        if(a < 0)a += m;
        sum += a;
        G[x[i]].pb(a - 1);
        b = x[i] - (a - 2);
        if(b <= 0)b += m;
        y[b]++;
    }
    //1番のをお気に入りにした時のを求める
    num = 0;
    for(i=1;i<n;i++){
        a = x[i] - x[i-1];
        if(a < 0)a += m;
        b = x[i];
        if(b < 0)b += m;
        num += min(a,b);
        if(b < a)c++;
    }
    z[1] = num;
    a = c;
    for(i=2;i<=m;i++){
        num = z[i-1];
        for(k=0;k<G[i-1].size();k++){
            num += G[i-1][k];
            a--;
        }
        //assert(a >= 0);
        a += y[i];
        z[i] = num - a;
    }
    ans = INF;
    for(i=1;i<=m;i++){
        ans = min(ans,z[i]);
       // pe(i);p(y[i]);
    }
    p(ans);
    
    return 0;
}

