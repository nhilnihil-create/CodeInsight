#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int H,W,h,w;
	scan(H);scan(W);scan(h);scan(w);
	if(H%h==0&&W%w==0){
		prin("No");
	}
	else if(W%w!=0){
		prin("Yes");
		int s[501];
		int a[500];
		s[0]=0;
		for(int i=w;i<=W;i+=w){
			s[i]=s[i-w]-1;
		}
		for(int i=W;i>=1;i--){
			if(i%w==0) continue;
			if(i+w>W){
				s[i]=1;
			}
			else{
				s[i]=s[i+w]+1;
			}
		}
		rep(i,W){
			a[i]=s[i+1]-s[i];
		}
		rep(i,H){
			rep(j,W){
				printf("%d ",a[j]);
			}
			kaigyo;
		}
	}
	else{
		prin("Yes");
		swap(h,w),swap(H,W);
		int s[501];
		int a[500];
		s[0]=0;
		for(int i=w;i<=W;i+=w){
			s[i]=s[i-w]-1;
		}
		for(int i=W;i>=1;i--){
			if(i%w==0) continue;
			if(i+w>W){
				s[i]=1;
			}
			else{
				s[i]=s[i+w]+1;
			}
		}
		rep(i,W){
			a[i]=s[i+1]-s[i];
		}
		rep(i,W){
			rep(j,H){
				printf("%d ",a[i]);
			}
			kaigyo;
		}
	}
	return 0;
}
