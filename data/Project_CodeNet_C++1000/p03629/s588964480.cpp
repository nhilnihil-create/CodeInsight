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
#include <time.h>

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
#define hoge cout << hoge << endl;
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
ll n,m,num,sum,ans;
ll a,b,c,d,e,f,g,h,w;
ll x[500005],y[500005],z[1000005];
char s[500005],t[100000];
bool flag;
ll dp[30];
ll le[100005],ri[100005];

void f2(ll d,ll i){
	bool check[30];
	flag = false;
	for(int j=d;j<=i;j++){
		if(flag){
			check[s[j]-'a'] = true;
		}
		if(s[j] == 'a'){
			flag = true;
		}
	}
	t[0] = 'a';
	for(ll j=0;j<='z'-'a';j++){
		if(!check[j]){
			t[1] = (char)(j);
		}
	}
	return ;
}
void fn(ll d,ll i){
	//num+1文字目を決める
	flag = false;
	bool check[30];
	for(ll j=d+1;j<=i;j++){
		if(flag){
			check[j-'a'] = true;
		}
		if(s[j] == t[num]){
			flag = true;
		}
	}
	for(ll j=0;j<='z'-'a';j++){
		if(!check[j]){
			t[num+1] = (char)(j+'a');
		}
	}
	return ;
}
void fl(ll d,ll i){
	bool check[30];
	for(ll j=d;j<=i;j++){
		check[s[i] - 'a'] = true;
	}
	for(ll j=0;j<='z'-'a';j++){
		if(!check[j]){
			t[num] = (char)(j+'a');
		}
	}
	return ;

}

int main(){	
	cin >> s;
	f = 0;
	n = strlen(s);
	d = n-1;
	for(i=n-1;i>=0;i--){
		dp[s[i] - 'a']++;
		e++;
		c = 0;
		for(j=0;j<='z'-'a';j++){
			if(dp[j] == 0){
				c = 1;
				break;
			}
		}
		if(c == 0){
			//全部1以上

			for(j=0;j<='z'-'a';j++)dp[j] = 0;
			e=0;
		//	for(j=i;j<=d;j++)pu(s[j]);
		//	el;
			le[num] = i;
			ri[num] = d;
			//pe(le[num]);p(ri[num]);
			num++;
			d = i-1;
			//p("--------");
		}
	}
	le[num] = 0;
	ri[num] = d;
	for(i=num;i>=0;i--){
		ll left = le[i],right = ri[i];
		if(i==num){
			bool check[30];
			for(j=0;j<='z'-'a';j++)check[j]=false;
			for(j=left;j<=right;j++){
				check[s[j]-'a'] = true;
			}
			for(j=0;j<='z'-'a';j++){
				if(!check[j]){
					//p("hoge");
					t[f] = (char)(j+'a');
					f++;
					break;
				}
			}
		}else{
			bool check[30];
			flag = false;
			for(j=0;j<='z'-'a';j++)check[j]=false;
			for(j=left;j<=right;j++){
				if(flag){
					check[s[j]-'a'] = true;
				}
				if(s[j] == t[f-1] && !flag){
					flag = true;
				}				
			}
			for(j=0;j<='z'-'a';j++){
				if(!check[j]){
					t[f] = (char)(j+'a');
					f++;
					break;
				}
			}
		}
	}
			
	//for(j=0;j<=d;j++)pu(s[j]);
	//el;
	//if(e != 0)fl(d,n-1);
	//p(num);
	p(t);

		

	
	return 0;
}
