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
/*
vector<ll> G[500005];
vector<P> tree[500010];

//big priority queue
priority_queue <ll> pql;
priority_queue <P> pqp;

//small priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
*/
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


ll i,j,k,ii,jj;
ll n,m;
ll a,b,c,d,e,g,h,r;
ll l;
ll num;
ll x[500005],y[500005],z[500005];
ll ans[180000];
bool dame;
char s[500005];

void solve2(){
	a = 0;
	for(i=0;i<m;i++){
		if(x[i] % 2 == 1){
			b = x[a];
			x[a] = x[i];
			x[i] = b;
			if(a == m-1)break;
			a = m-1;
		}
	}
	for(i=0;i<m;i++){
		pe(x[i]);
	}
	el;
	k = m + 1;
	y[0] = x[0] - 1;
	if(y[0] == 0)k--;
	y[1] = 2;
	for(i=1;i<m-1;i++){
		y[i+1] = x[i];
	}
	y[m] = x[m-1]-1;
	if(y[m] == 0)k--;
	p(k);
	for(i=0;i<=m;i++){
		if(y[i] == 0)continue;
		pe(y[i]);
	}
	return;
}
void solve1(){
	for(i=0;i<m;i++){
		if(x[i] % 2 == 1){
			b = x[i];
			x[i] = x[0];
			x[0] = b;
			break;
		}
	}
	for(i=0;i<m;i++){
		pe(x[i]);
	}
	el;
	p(m);
	pe(x[0]+1);
	for(i=1;i<m-1;i++){
		pe(x[i]);
	}
	p(x[m-1]-1);
}

int main(){
    
    cin >> n >> m;
	k = n;
	for(i=0;i<m;i++){
		cin >> x[i];
		a += x[i]/2;
		if(x[i] % 2 == 1)b++;
	}

	if(a + n/2 < n-1){
        p("Impossible");
	}else if(m == 1){
		p(x[0]);
		if(x[0] % 2 == 1){
			p((n+1)/2);
			while(n >= 2){
				pe(2);
				n -= 2;
			}
			p(1);
		}else{
			if(n != 2){
				p(2);
				pe(2);
				p(n-2);
			}else{
				p(2);
				pe(1);p(1);
			}
		}

	}else if(b == 0){
		//assert(n == -1);
		for(i=0;i<m;i++){
			pe(x[i]);
		}
		el;
		p(m);
		pe(x[0] + 1);
		for(i=1;i<m-1;i++)pe(x[i]);
		p(x[m-1]-1);
	}else if(b == 2){
		solve2();
	}else{
		solve1();
	}
    
   
    return 0;
}