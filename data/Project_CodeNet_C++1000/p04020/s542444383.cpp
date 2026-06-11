#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
int main(){
	int n;
	cin>>n;
	int a[n+1];
	a[n]=0;
	in(a,n);
	ll count=0;
	rep(i,n){
		count+=a[i]/2;
		if(a[i]%2&&a[i+1]){
			count++;
			a[i+1]--;
		}
	}
	cout<<count;
	return 0;
}