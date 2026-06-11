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
char dir[] = "RULD";
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
ll n,m,num,ans,sum;
ll a,b,c,d,e,g,h,w;
ll x[500005],y[500005],z[500005];
ll l1[500005],l2[500005];

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
	cin >> a >> b >> r >> c >> d >> r >> r;
	r = 0;
	//ans += b;
	for(i=0;i<=min(a,min(c,d));i++){
		num = (a - i)/2 + (c - i)/2 + (d - i)/2;
		sum = b + num * 2 + 3 * i;
		ans = max(ans,sum);
		k ++;
		if(k >= 10)break;
	}

	p(ans);


	//p(ans);
    return 0;
}