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
#define line cout << "----------" << endl;


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
void Yay(bool condition){

    if(condition){
        p("Yay!");
    }else{
        p(":(");
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

ll n,m,num,ans,a,b,c,d,e,g,h,w,i,j,k,q;
ll x[500005],y[500005],z[500005];
ll sum[500005],lsum[500005];
char s[500005],t[500005];

void sum_init(){

	for(i=1;i<=n;i++){
		sum[i] = sum[i-1] + x[i-1];
		if(x[i-1] >= 0){
			lsum[i] = lsum[i-1] + x[i-1];
		}else{
			lsum[i] = lsum[i-1];
		}
	}
	return;
}

ll all_sum(ll left,ll right){
	if(right < left){
		return 0;
	}else{
		return sum[right + 1] - sum[left];
	}
}

ll like_sum(ll left,ll right){
	if(right < left){
		return 0;
	}else{
		return lsum[right + 1] - lsum[left];
	}
}

void solve(ll left,ll right){
	ll ret1 = 0,ret2 = 0;
	ret1 += like_sum(0,left-1);
	ret1 += all_sum(left,right);
	ret1 += like_sum(right+1,n-1);
	ans = max(ans,ret1);
	ret2 += like_sum(0,left-1);
	ret2 += like_sum(right+1,n-1);
	ans = max(ans,ret2);
	return ;
}

int main(){
	cin >> n >> k;
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	sum_init();
	ans = 0;
	for(i=0;i+k-1<n;i++){
		solve(i,i+k-1);
		//p(ans);
	}
	p(ans);
	
	return 0;
}
