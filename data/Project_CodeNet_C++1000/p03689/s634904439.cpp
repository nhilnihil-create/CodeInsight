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
char dir[] = "DRUL";
ll bit[500005];
//↓,→,↑,←

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(15)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
    //abcのbed乗を計算する
    if(bed==0){return 1;}
    else{
        ll ced = rui(abc,bed/2);
        ced *= ced;
        ced %= mod;
        if(bed%2==1){ced*=abc; ced%=mod;}
        return ced;
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

ll i,j,k,ii,jj,r,l;
ll n,num,sum,ans;
ll a,b,c,d,e,g,h,w;
ll x[500005],y[500005],z[500005];
bool dp[10000];
char s[500005];

ll bitsum(ll i){
	ll s = 0;
	while(i>0){
		//p("hoi");
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void bitadd(ll b,ll x){
	while(b <= n){
		//p("hoi");
		bit[b] += x;
		b += b & -b;
	}
}

int main(){
	cin >> h >> w >> a >> b;
	c = 260;
	num = (h/a) * (w/b);
	ll pos,nega;
	pos = (h * w - num) * c;
	nega = ((a * b - 1) * c + 1) * num;
	if(pos > nega){
		p("Yes");
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				if(i % a == 0 && j % b == 0){
					pe(-1 * (a * b - 1) * c - 1);
				}else{
					pe(c);
				}
			}
			el;
		}
	}else{
		p("No");
	}
	return 0;
}
