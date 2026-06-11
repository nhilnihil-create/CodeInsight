#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF LLONG_MAX
#define eps LDBL_EPSILON
#define moder 1000000007
#define pie 3.141592653589793238462643383279
#define P std::pair<int,int>
#define prique priority_queue
using namespace std;
int n,a[310][310],sum;
bool used[310][310];
signed main(){
	cin>>n;
	rep(i,n){
		rep(j,n){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	rep(i,n){
		rep(j,n){
			if(i==j)continue;
			rep(k,n){
				if(i==k)continue;
				if(j==k)continue;
				if(a[i][j]>a[i][k]+a[k][j]){
					cout<<-1<<endl;
					return 0;
				}
				if(a[i][j]==a[i][k]+a[k][j]&&!used[i][j]){
					sum-=a[i][j];
					used[i][j]=true;
				}
			}
		}
	}
	cout<<sum/2<<endl;
	return 0;
}