#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define F first
#define S second
#define f(i,n) for(int i=0;i<(n);i++)
#define INF LLONG_MAX/3
#define mod 1000000007
#define pie 3.141592653589793238462643383279
#define prique priority_queue
using namespace std;
P p[510];
signed main(){
	int n,sum=0;
	cin>>n;
	f(i,n){
		cin>>p[i].F;
		p[i].S=i+1;
	}
	sort(p,p+n);
	f(i,n){
		if(sum+p[i].S>p[i].F||n*(n-1)/2+1-sum+i*(n+1)<p[i].F){
			puts("No");
			return 0;
		}
		sum+=p[i].S;
	}
	puts("Yes");
	int cnt=1;
	f(i,n){
		f(j,p[i].S-1){
			if(cnt==p[lower_bound(p,p+n,make_pair(cnt,(int)(0)))-p].F){
				cout<<p[lower_bound(p,p+n,make_pair(cnt,(int)(0)))-p].S<<" ";
				j--;
			}
			else cout<<p[i].S<<" ";
			cnt++;
		}
	}
	f(i,n){
		f(j,n-p[i].S){
			if(cnt==p[lower_bound(p,p+n,make_pair(cnt,(int)(0)))-p].F){
				cout<<p[lower_bound(p,p+n,make_pair(cnt,(int)(0)))-p].S<<" ";
				j--;
			}
			else cout<<p[i].S<<" ";
			cnt++;
		}
	}
	for(int i=cnt;i<=n*n;i++){
		cout<<p[lower_bound(p,p+n,make_pair(cnt,(int)(0)))-p].S<<" ";
	}
    return 0;
}
