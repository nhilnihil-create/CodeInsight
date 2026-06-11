#include <bits/stdc++.h>
using namespace std;
#define	fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input(n,arr)    for(int i=0;i<n;i++)cin>>arr[i]; // 0 => n
#define	pi 3.14159265358979323846
#define	endl "\n"
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e18; 
const int N = 1e5+5 , oo=0x3f3f3f3f , mod=1e9+7;
void file(){freopen("out.txt","w",stdout);/*freopen("in.txt","r",stdin);*/}
int a[N];

int main(){
	fast
	ll a,b,n;
	cin>>a>>b>>n;
	if(a==0){
		cout<<b/n+1<<endl;
		return 0;
	}
	if(a==b){
		if(n==a)
			cout<<1;
		else
			cout<<0;
	return 0;
	}

	cout<<b/n-(a%n==0?a/n-1:a/n);
	
	return 0;
}