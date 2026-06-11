#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int q_sort(int d[],int left,int right);
long long func(long long a,long long n);
int main(void)
{
	int n; cin>>n;
	int a[n]; for(int i = 0; i < n; i++) cin>>a[i];
	q_sort(a,0,n-1);
	long long ans = 0;
	if(n%2 == 0){
		for(int  i = 0; i < n; i+=2){
			if(a[i] != a[i+1] || a[i+1] != i+1){
				cout<<0<<endl;
				return 0;
			}
		}
		ans = func(2,n/2);
	}
	else{
		if(a[0] != 0){
			cout<<0<<endl;
		}
		for(int i = 1; i < n; i+=2){
			if(a[i] != a[i+1] || a[i+1] != i+1){
				cout<<0<<endl;
				return 0;
			}
		}
		ans = func(2,n/2);
	}
	
	cout<<ans<<endl;
	
	return 0;
}


int q_sort(int d[],int left,int right){
	if(left >= right) return 0;
	int pipot = d[(left+right)/2], l = left, r = right, tmp;
	while(l<r){
		while(d[l] < pipot) l++;
		while(d[r] > pipot) r--;
		if( l <=  r){
			tmp = d[l];
			d[l] = d[r];
			d[r] = tmp;
			l++;
			r--;
		}
	}
	q_sort(d,left,r);
	q_sort(d,l,right);
}

long long func(long long a, long long n){
	long long re = 1;
	while(n > 0){
		if(n & 1) re = re * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return re;
}
