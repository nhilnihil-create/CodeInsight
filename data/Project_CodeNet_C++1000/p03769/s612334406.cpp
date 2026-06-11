#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q[21000],tail;
ll com(ll n,ll m){
	if(n<m) return 0;
	ll ret = 1;
	for(int i=0,j=1;i<m;i++){
		ret*=n-i;
		while(j<=m && ret%j==0){
			ret/=j;
			j++;
		}
	}
	return ret;
}
ll f[30];
int g[30];
int a[100];
int main(){
	ll n;
	cin>>n;
	int now  = 0;
	while(n){
		for(int i = 63;i>1;i--) if((1ll<<i-1)-1<=n){
			n -= (1ll<<i-1)-1;
			//now++;
			//cout<<i<<endl;
			int num = 0;
			memset(a,0,sizeof(a));
			bool flag = true;
			while(n>0 && flag){
				flag =false;
				ll mx =0;
				int p= 0;
				for(int j = 0;j*2<=i;j++){
					ll tmp = 0;
					for(int k = 0;k<=j;k++) tmp+=com(j,k)*com(i-j,k);
					if(tmp>mx && tmp<=n) {
						mx = tmp;
						p = j;
					}
				}
				if(p>0){
					flag = true;
					a[++num] = p;
					n-= mx;
				}
			}
			if(num){
				sort(a+1,a+num+1);
				reverse(a+1,a+num+1);
				for(int j =0;j<i-a[1];j++) q[tail++] = now+1;
				for(int k = 1;k<=num;k++){
				 	q[tail++] = now+k+1;
					for(int j = 0;j<a[k]-a[k+1];j++) q[tail++] = now+1;
				}
				for(int k = num;k>0;k--) q[tail++] = now+k+1;
				now+=num+1;
			} else{
				for(int j = 0;j<i;j++) q[tail++] = now+1;
				now++;
			}
			
			break;
		}
	}
	cout<<tail<<endl;
	for(int i =0;i<tail;i++) cout<<q[i]<<' ';
	puts("");
	return 0;
}