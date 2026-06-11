#include <bits/stdc++.h>

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
	int w = 2 * n;
	int L[w];
	for(int i = 0; i < 2*n; i++) cin>>L[i];
	q_sort(L,0,2*n-1);
	for(int i = 0; i < 2*n; i++){
		//cout<<" i = "<<i<<", L[i] = "<<L[i]<<endl;
	}
	long long ans = 0;
	for(int i = 0; i < 2*n; i+=2){
		ans+=L[i];
	}
	cout<<ans<<endl;
	return 0;
}

