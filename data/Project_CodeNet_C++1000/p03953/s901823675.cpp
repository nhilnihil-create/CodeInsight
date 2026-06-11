#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10;
ll X[N],a[N],change[N],ans[N],tmp[N],loc[N];
int n,m;
ll K;
inline void prework(){
    for(int i=1;i<=n;++i){
    	change[i]=i;
	}
    for(int i=1;i<=m;++i){
    	swap(change[a[i]],change[a[i]+1]);
	}
}
inline void solve(long long y){
    for(int i=1;i<=n;++i){
    	ans[i]=i;
	}
    for(;y;y>>=1){
		if(y&1){
			for(int i=1;i<=n;++i){
				tmp[i]=ans[change[i]];
			}
			for(int i=1;i<=n;++i){
				ans[i]=tmp[i];
			}
		}
		for(int i=1;i<=n;++i){
			tmp[i]=change[change[i]];
		}
		for(int i=1;i<=n;++i){
			change[i]=tmp[i];
		}
	}
	for(int i=1;i<=n;++i){
		tmp[i]=X[ans[i]];
	}
	for(int i=1;i<=n;++i){
		X[i]=tmp[i];
	}
}
int main(){
	cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>loc[i];
    	X[i]=loc[i]-loc[i-1];
    }
    cin>>m>>K;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
    prework();
    solve(K);
    long long now=0;
    for(int i=1;i<=n;++i){
        now+=X[i];
        printf("%lld.0\n",now);
    }
    return 0;
}