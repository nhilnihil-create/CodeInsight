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
ll a,b,c,d,e,g,h;
ll ans,num;
ll x[500005],y[500005],z[500005];
ll l[500005],r[500005];
bool dame,flag;
bool check[500005];
char s[500005],t[500005];

int main(){
    cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> l[i] >> r[i];
	}
	for(i=0;i<n;i++){
		//pe("i");pe("=");p(i);
		num = 1;
		ll ba=INF,bb=INF;
		if(l[i] == r[i]){
			for(j=1;j*j<=l[i];j++){
				if(l[i] % j == 0){
					x[j] += 1;
					x[j+1] -= 1;
					if(j*j != l[i]){
						x[l[i]/j] += 1;
						x[l[i]/j + 1] -= 1;
					}
				}
			}
		}else{
			while(1){
				if(num >= 2){
					ba = a;
					bb = b;
				}
				a = (l[i]+num-1)/num;
				b = (r[i])/num;
				b = min(b,ba-1);
				a = min(a,b);
				if(b == 0)break;
				if(a != b){
					x[a] += 1;
					x[b + 1] -= 1;
				}else{
					if(r[i]/a != (l[i]-1)/a){
						x[a] += 1;
						x[a + 1] -= 1;
					}
				}
				//pe(a);p(b);
				if(b <= r[i]-l[i])break;
				num++;
			}
			if(a >= 2){
				x[1] += 1;
				x[a] -= 1;
			}
		}
		//pe("x[1]=");p(x[1]);
	}
	for(i=1;i<=m;i++){
		x[i] += x[i-1];
		p(x[i]);
	}


	return 0;

}
