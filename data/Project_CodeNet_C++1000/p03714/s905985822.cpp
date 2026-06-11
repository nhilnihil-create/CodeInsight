#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;

typedef long long ll;

const int maxn = 300010;

int n;
ll a[maxn],pre[maxn],aft[maxn];

priority_queue<ll> y; // 大根堆 
priority_queue<ll, vector<ll>,greater<ll> > x; // 小根堆 

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	n = read();
	for(int i = 1;i <= 3*n ;i++) { a[i] = read(); }
	 
	for(int i = 1;i <= n;i++){
		x.push(a[i]);
		pre[i] = pre[i-1] + a[i];
	}
	
	
	for(int i = n + 1;i <= 2 * n; i++) {
		int cur = x.top(); 
		pre[i] = pre[i-1];
		if(a[i] > cur){
			x.pop();
			pre[i] -= cur;
			pre[i] += a[i];
			x.push(a[i]);
		}
	}
	
//	for(int i=1;i<=2*n;i++){
//		printf("%d ",pre[i]);
//	}printf("\n");
	
	for(int i = 3 * n; i >= 2 * n + 1 ;i--){
		y.push(a[i]);
		aft[i] = aft[i+1] + a[i];
	}
		
//	bug
	
	for(int i = 2 * n; i > n ;i--){
		int cur = y.top();
		aft[i] = aft[i+1];
		if(a[i] < cur){
			y.pop();
			aft[i] -= cur;
			aft[i] += a[i];
			y.push(a[i]);
		}
	}
	
//	for(int i=3*n;i>n;i--){
//		printf("%d ",aft[i]);
//	}printf("\n");
	
	ll ans = -1000000000000000ll;
	for(int i = n;i <= 2 * n;i++){
		ans = max(ans , pre[i] - aft[i+1]);
//		bug2(ans);
	}
	
	printf("%lld\n",ans);
	
	return 0;
}