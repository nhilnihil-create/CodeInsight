/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
LL a[100000+20],miu[200000+20],k[200000+20];
LL sum,l; 

int main(){
	fastio;
	R(n);
	if(n==1){
		cout<<"YES"<<endl;
		return 0;
	}
	rb(i,1,n){
		R(a[i]);
		sum+=a[i];
	}
	if(sum%(1ll*n*(n+1)/2)){
		cout<<"NO"<<endl;
		return 0;
	}
	l=sum/(1ll*n*(n+1)/2);
	a[0]=a[n];
	rb(i,1,n){
		if(a[i-1]-a[i]+l<0||(a[i-1]-a[i]+l)%n!=0)
		{	
			cout<<"NO"<<endl;
		return 0;
		}
		k[i]=(a[i-1]-a[i]+l)/n;
	}
	rb(i,1,n)
		k[i+n]=k[i];
	int cnt=0;
	LL sumsum=0;
	rb(i,1,2*n){
		cnt+=k[i];
		sumsum+=cnt;
		miu[i]=sumsum;
//		cout<<miu[i]<<"_" ;
		if(i>n){
			cnt-=k[i-n];
			miu[i]-=k[i-n]*(n+1);
			sumsum-=k[i-n]*(n+1);
		}
//		cout<<miu[i]<<" "<<sumsum<<endl;;
	}
	rb(i,1,n){
		int is=n+i;
		if(i==n)
			is=n;
//		cout<<k[i]<<" "<<miu[is]<<endl;
		if(miu[is]!=a[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
/** 程序框架：
  *
  *
  *
  *
  **/
