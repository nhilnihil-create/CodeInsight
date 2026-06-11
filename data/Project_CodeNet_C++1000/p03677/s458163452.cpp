#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

struct BIT{
	int siz;
	ll s[(1<<17)+1];
	void init(){
		siz = 1<<17;
		for(int i = 1 ; i <= siz ; i ++){
			s[i] = 0;
		}
	}
	void add(int k,ll x){
		while(k > 0){
			s[k] += x;
			k -= k&-k;
		}
	}
	void add_range(int a,int b,ll x){
		add(b,x);
		if(a != 1)add(a-1,-x);
	}
	ll sum(int k){
		ll ret = 0;
		while(k <= siz){
			ret += s[k];
			k += k&-k;
		}
		return ret;
	}
}A,B;

int main(){
	static int n,m;
	static ll a[100010];
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	A.init();
	B.init();
	for(int i = 1 ; i+1 <= n ; i ++){
		if(a[i] < a[i+1]){
			B.add_range(1,a[i],a[i+1]-a[i]);
			A.add_range(a[i]+1,a[i+1],-1);
			B.add_range(a[i]+1,a[i+1],a[i+1]+1);
			B.add_range(a[i+1]+1,m,a[i+1]-a[i]);
		}
		else {
			A.add_range(1,a[i+1],-1);
			B.add_range(1,a[i+1],a[i+1]+1);
			B.add_range(a[i+1]+1,a[i],m+a[i+1]-a[i]);
			A.add_range(a[i]+1,m,-1);
			B.add_range(a[i]+1,m,m+a[i+1]+1);
		}
	}
	
	ll ret = 1000000000000000000;
	for(int i = 1 ; i <= m ; i ++){
		ret = min( ret , A.sum(i)*i + B.sum(i) );
	}
	cout << ret << endl;
}

