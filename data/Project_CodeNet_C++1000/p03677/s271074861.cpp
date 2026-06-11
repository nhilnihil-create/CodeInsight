#include <iostream>

using namespace std;
long long a[100010],t[100010],s[100010];
int main(){
	long long i,j,n,m;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(i=0;i<=100010;i++){
		t[i] = 0;
		s[i] = 0;
	}
	for(i=1;i<n;i++){
		if(a[i-1]<a[i]){
			t[1] += a[i]-a[i-1];
			t[a[i-1]+1] -= a[i]-a[i-1];
			t[a[i-1]+1] += a[i]+1;
			s[a[i-1]+1] += -1;
			t[a[i]+1] -= a[i]+1;
			s[a[i]+1] -= -1;
			t[a[i]+1] += a[i]-a[i-1];
		}else{
			t[1] += a[i]+1;
			s[1] += -1;
			t[a[i]+1] -= a[i]+1;
			s[a[i]+1] -= -1;
			t[a[i]+1] += a[i]+m-a[i-1];
			t[a[i-1]+1] -= a[i]+m-a[i-1];
			t[a[i-1]+1] += a[i]+m+1;
			s[a[i-1]+1] += -1;
		}
	}
	
	for(i=1;i<=m+1;i++){
		t[i+1] += t[i];
		s[i+1] += s[i];
	}
	for(i=0;i<=m;i++){
		s[i] *= i;
	}
	long long ans=200000000000;
	for(i=1;i<=m;i++){
		ans = min(ans,t[i]+s[i]);
	}
	cout << ans << endl;
}
	