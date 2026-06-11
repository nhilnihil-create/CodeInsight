#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL (long long)
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,/*<=1e5*/a[200000+10];
bool flag[2*(100000)+10];
int sz;
bool check(int x){
	rb(i,1,sz){
		if(a[i]>=x){
			flag[i]=1;
		}
		else{
			flag[i]=0;
		}
	}
	int fir1=-INF,fir0=-INF,last1=INF,last0=INF;
	rb(i,2,n){
		if(flag[i]==1&&flag[i-1]==1){
			fir1=i;
		}
	}
	rb(i,2,n){
		if(flag[i]==0&&flag[i-1]==0){
			fir0=i;
		}
	}
	rl(i,sz-1,n){
		if(flag[i]==1&&flag[i+1]==1){
			last1=i;
		}
	}
	rl(i,sz-1,n){
		if(flag[i]==0&&flag[i+1]==0){
			last0=i;
		}
	} 
	if(fir1==-INF&&fir0==-INF&&last1==INF&&last0==INF){
		return flag[1];
	}
	int best1=INF,best0=INF;
	if(last1>=n){
		best1=min(best1,last1-n);
	}
	if(fir1<=n){
		best1=min(best1,n-fir1);
	}
	if(last0>=n){
		best0=min(best0,last0-n);
	}
	if(fir0<=n){
		best0=min(best0,n-fir0);
	}
	if(best1>best0){
		return false;
	}
	else{
		return true; 
	} 
}
int main(){
	scanf("%d",&n);
	sz=(n<<1)-1;
	rb(i,1,sz){
		scanf("%d",&a[i]);
	}
	int l=1,r=2*n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
//		cout<<l<<" "<<r<<endl;
	}
//	cout<<check(5)<<endl;
	printf("%d\n",l);
	return 0;
}
