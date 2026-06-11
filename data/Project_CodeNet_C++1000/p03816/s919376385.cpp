#include <bits/stdc++.h>
#define max 100010

using namespace std;


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

int main(void)
{
	int n; cin>>n;
	int a[n]; for(int i = 0; i < n; i++) cin>>a[i];
	q_sort(a,0,n-1);
	int syurui[max]; for(int i = 0; i < max; i++) syurui[i] = 0;
	for(int i = 0; i < n; i++) syurui[a[i]]++;
	int ans = 0;
	for(int i = 0; i < max; i++){
		if(syurui[i] != 0) ans++;
	}
	
	int two_num = 0, one_num = 0;
	for(int i = 0; i < max; i++){
		if(syurui[i] >= 2 && syurui[i] % 2 == 0){
			syurui[i] = 2;
			two_num++;
		}
		else if(syurui[i] > 2 && syurui[i] % 2 == 1) syurui[i] = 1;
	}
	if(two_num % 2 == 1) ans--;
	//cout<<"two_num = "<<two_num<<", ans = "<<ans<<endl;
	cout<<ans<<endl;
	return 0;
}

