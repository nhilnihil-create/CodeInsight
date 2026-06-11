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
#include <time.h>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
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
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl


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
    }}
ll gcd(ll number1,ll number2){
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }}
void YES(bool condition){
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;}

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

ll n,m,num,sum,ans,a,b,c,d,e,g,h,w,i,j,k,q,l,r;
ll x[500005],y[500005],z[1200005];
ll dp[1005][1005];
bool flag,dame;
ll sta;
ll po[1200000];

int main(){
	cin >> h >> w >> n;
	if(n % 2 == 1){
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if((i + j) % 2 == 1)pu("R");
				if((i + j) % 2 == 0)pu("G");
			}
			el;
		}
		return 0;
	}else{
		ll syuki = 2 * n;
		for(i=0;i<2*n;i++){
			for(j=0;j<2*n;j++){
				a = 0;
				if(0 <= (i + j) % syuki && ((i + j) % syuki) < n)a += 2;
				if(0 <= ((i - j + 1000 * syuki) % syuki) && ((i - j + 1000 * syuki) % syuki) < n)a += 1;
				dp[i][j] = a;
			}
		}
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				a = i % syuki;
				b = j % syuki;
				if(dp[a][b] == 1)pu("R");
				if(dp[a][b] == 2)pu("Y");
				if(dp[a][b] == 3)pu("G");
				if(dp[a][b] == 0)pu("B");
			}
			el;
		}
	}
	return 0;
}